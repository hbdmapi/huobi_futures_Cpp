#pragma once

#include <libwebsockets.h>
#include <ctime>
#include <stdbool.h>

#include <string>
using std::string;

#include <glog/logging.h>
#include <thread>
#include <chrono>

#include <list>
using std::list;

#include <mutex>
using std::mutex;

#include "huobi_futures/utils/gzip.hpp"
#include "huobi_futures/utils/const_val.hpp"

typedef std::function<void()> _OnClose;
typedef std::function<void()> _OnOpen;
typedef std::function<void(const char *data, int len)> _OnError;
typedef std::function<void(const char *data, int len)> _OnMsg;

namespace huobi_futures
{
    namespace wsbase
    {
        class WebSocket
        {
        public:
            _OnClose OnClose;
            _OnOpen OnOpen;
            _OnError OnError;
            _OnMsg OnMsg;

            WebSocket()
            {
                OnClose = NULL;
                OnOpen = NULL;
                OnError = NULL;
                OnMsg = NULL;

                has_closed = false;
            }

            ~WebSocket()
            {
                if (context)
                {
                    lws_context_destroy(context);
                }
            }

            bool Connect(const string &url)
            {
                string name;
                string host;
                int port;
                string path;
                if (!GetUrlInfo(url, name, host, port, path))
                {
                    return false;
                }

                static const struct lws_protocols protocols[] = {
                    {
                        "lws-minimal-broker",
                        callback,
                        0,
                        utils::WS_RECV_BUF_SIZE,
                    },
                    {NULL, NULL, 0, 0}};

                lws_context_creation_info ctx_info;
                memset(&ctx_info, 0, sizeof ctx_info);
                ctx_info.port = CONTEXT_PORT_NO_LISTEN;
                ctx_info.protocols = protocols;
                ctx_info.fd_limit_per_thread = 3;
                if (name == "wss")
                {
                    ctx_info.options |= LWS_SERVER_OPTION_DO_SSL_GLOBAL_INIT;
                }

                context = lws_create_context(&ctx_info);
                if (!context)
                {
                    LOG(ERROR) << "lws_create_context error.";
                    return false;
                }

                lws_client_connect_info conn_info;
                memset(&conn_info, 0, sizeof(conn_info));
                conn_info.context = context;
                conn_info.protocol = name.c_str();
                conn_info.address = host.c_str();
                conn_info.host = host.c_str();
                conn_info.origin = host.c_str();
                conn_info.port = port;
                conn_info.path = path.c_str();
                conn_info.userdata = (void *)this;
                if (name == "wss")
                {
                    conn_info.ssl_connection = LCCSCF_USE_SSL | LCCSCF_ALLOW_SELFSIGNED | LCCSCF_SKIP_SERVER_CERT_HOSTNAME_CHECK;
                }

                wsi = lws_client_connect_via_info(&conn_info);
                if (!wsi)
                {
                    LOG(ERROR) << "lws_client_connect_via_info error:" << url;
                    return false;
                }
                return true;
            }

            void SendMsg(const string &data)
            {
                std::unique_lock<std::mutex> lck(mtx);
                data_buf.push_back(data);

                lws_callback_on_writable(wsi);
            }

            void RunForever()
            {
                while (!has_closed)
                {
                    try
                    {
                        lws_service(context, 0);
                    }
                    catch (...)
                    {
                        break;
                    }
                }
            }

        private:
            bool GetUrlInfo(const string &in_url, string &out_name, string &out_host, int &out_port, string &out_path)
            {
                int index = in_url.find("://");
                if (index == -1)
                {
                    LOG(ERROR) << "url is error, such as ws://host/path or wss://host/path";
                    return false;
                }

                out_name = in_url.substr(0, index);
                out_port = 0;
                if (out_name == "ws")
                {
                    out_port = 80;
                }
                else if (out_name == "wss")
                {
                    out_port = 443;
                }
                if (out_port == 0)
                {
                    LOG(ERROR) << "url is error, such as ws://host/path or wss://host/path";
                    return false;
                }

                out_host = in_url.substr(index + 3);
                index = out_host.find("/");
                if (index != -1)
                {
                    out_path = out_host.substr(index);
                    out_host = out_host.substr(0, index);
                }

                index = out_host.find(":");
                if (index != -1)
                {
                    out_port = atoi(out_host.substr(index + 1).c_str());
                    out_host = out_host.substr(0, index);
                }
                return true;
            }

            static int callback(struct lws *wsi,
                                enum lws_callback_reasons reason,
                                void *user,
                                void *in,
                                size_t len)
            {
                WebSocket *p_cls_obj = (WebSocket *)user;

                string message;
                switch (reason)
                {
                case LWS_CALLBACK_CLIENT_ESTABLISHED:
                    if (p_cls_obj->OnOpen)
                        p_cls_obj->OnOpen();
                    break;

                case LWS_CALLBACK_CLIENT_WRITEABLE:
                {
                    std::unique_lock<std::mutex> lck(p_cls_obj->mtx);
                    for (auto item : p_cls_obj->data_buf)
                    {
                        uint8_t buf[LWS_PRE + utils::WS_SEND_BUF_SIZE] = {0};
                        int n = lws_snprintf((char *)buf + LWS_PRE, utils::WS_SEND_BUF_SIZE, "%s", item.c_str());
                        lws_write(wsi, buf + LWS_PRE, n, LWS_WRITE_TEXT);
                    }
                    p_cls_obj->data_buf.clear();
                }
                break;

                case LWS_CALLBACK_CLIENT_RECEIVE:
                    if (p_cls_obj->OnMsg)
                        p_cls_obj->OnMsg((char *)in, len);
                    break;

                case LWS_CALLBACK_CLIENT_CLOSED:
                    lws_cancel_service(lws_get_context(wsi));
                    if (p_cls_obj->OnClose)
                        p_cls_obj->OnClose();
                    p_cls_obj->has_closed = true;
                    break;

                case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
                    lws_cancel_service(lws_get_context(wsi));
                    if (p_cls_obj->OnError != NULL)
                        p_cls_obj->OnError((char *)in, len);
                    break;

                default:
                    //LOG(INFO) << "websocket reason:" << reason;
                    break;
                }

                return 0;
            }

            lws_context *context = NULL;
            lws *wsi = NULL;

            mutex mtx;
            list<string> data_buf;

            bool has_closed;
        };
    } // namespace wsbase
} // namespace huobi_futures
