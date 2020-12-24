#pragma once
#include <string>
using std::string;

#include <list>
using std::list;

#include "huobi_futures/wsbase/WebSocket.hpp"
typedef huobi_futures::wsbase::WebSocket WebSocket;

#include "huobi_futures/wsbase/WSAuthDate.hpp"
typedef huobi_futures::wsbase::WSAuthData WSAuthData;

#include "huobi_futures/url_base/HttpRequest.hpp"
typedef huobi_futures::url_base::HttpRequest HttpRequest;

#include "huobi_futures/utils/const_val.hpp"

#include <sstream>
using std::stringstream;

#include "huobi_futures/utils/Signer.hpp"

#include <ctime>

#include <map>
using std::map;
using std::pair;

#include "huobi_futures/nlohmann_json/json.hpp"
#include "huobi_futures/utils/gzip.hpp"

#include "huobi_futures/json_struct/json_struct.h"

typedef std::function<void(const string &)> _call_back_fun;

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace ws
        {
            class WebSocketOp
            {
            public:
                void RunForever()
                {
                    if (this->p_ws == NULL)
                    {
                        return;
                    }
                    this->p_ws->RunForever();
                }

            protected:
                WebSocketOp(const string &path, const string &host = utils::DEFAULT_HOST,
                            const string &access_key = "", const string &secret_key = "")
                {
                    this->host = host;
                    this->path = path;

                    this->ak = access_key;
                    this->sk = secret_key;

                    InitWs();
                }

                ~WebSocketOp()
                {
                    DispWs();
                }

                bool Connect()
                {
                    stringstream str_buf;
                    str_buf << "wss://" << host << path;
                    return p_ws->Connect(str_buf.str());
                }

                void Disconnect()
                {
                    DispWs();
                }

                bool Sub(const string &sub_str, const string &ch, _call_back_fun fun)
                {
                    if (sub_map_call_fun.find(ch) != sub_map_call_fun.end())
                    {
                        return true;
                    }
                    sub_map_call_fun.insert(pair<string, _call_back_fun>(ch, fun));

                    p_ws->SendMsg(sub_str);

                    LOG(INFO) << sub_str;

                    return true;
                }

                bool Unsub(const string &unsub_str, const string &ch)
                {
                    if (sub_map_call_fun.find(ch) == sub_map_call_fun.end())
                    {
                        return true;
                    }
                    p_ws->SendMsg(unsub_str);

                    LOG(INFO) << unsub_str;

                    return true;
                }

                bool Req(const string &reqStr, const string &ch, _call_back_fun fun)
                {
                    if (req_map_call_fun.find(ch) != req_map_call_fun.end())
                    {
                        return true;
                    }
                    req_map_call_fun.insert(pair<string, _call_back_fun>(ch, fun));

                    p_ws->SendMsg(reqStr);

                    LOG(INFO) << reqStr;

                    return true;
                }

            private:
                void InitWs()
                {
                    p_ws = new WebSocket();

                    p_ws->OnOpen = std::bind(&WebSocketOp::WsOnOpen, this);
                    p_ws->OnClose = std::bind(&WebSocketOp::WsOnClose, this);
                    p_ws->OnMsg = std::bind(&WebSocketOp::WsOnMsg, this, std::placeholders::_1, std::placeholders::_2);
                }

                void DispWs()
                {
                    delete p_ws;
                    p_ws = NULL;
                }

                void WsOnOpen()
                {
                    LOG(INFO) << "WebSocket opened";

                    if (ak != "" && sk != "")
                    {
                        time_t now;
                        time(&now);

                        char pchar_time[sizeof "2011-10-08T07:07:09"];
                        strftime(pchar_time, sizeof pchar_time, "%FT%T", gmtime(&now));

                        stringstream para;
                        para << "AccessKeyId=" << ak << "&SignatureMethod=HmacSHA256&SignatureVersion=2&Timestamp=" << HttpRequest::Instance().UrlEncode(pchar_time);

                        string signature = utils::Signer::CreateSignature("GET", host, path, para.str(), sk);

                        WSAuthData auth;
                        auth.AccessKeyId = ak;
                        auth.Signature = signature;
                        auth.Timestamp = string(pchar_time);

                        string auth_str = auth.ToJson();
                        p_ws->SendMsg(auth_str);
                    }
                }

                void WsOnClose()
                {
                    LOG(INFO) << "WebSocket close.";
                }

                void WsOnMsg(const char *data, int len)
                {
                    char buf[utils::WS_RECV_BUF_SIZE] = {0};
                    huobi_futures::utils::DecompressString(data, len, buf, utils::WS_RECV_BUF_SIZE);

                    string plaintext(buf);
                    nlohmann::json jdata = nlohmann::json::parse(plaintext);

                    if (jdata.contains("ping")) // market heartbeat
                    {
                        //LOG(INFO) << plaintext;

                        string pong = plaintext.replace(plaintext.find("ping"), 4, "pong");
                        p_ws->SendMsg(pong);

                        //LOG(INFO) << pong;
                    }
                    else if (jdata.contains("op"))
                    {
                        string op = jdata["op"].get<string>();
                        if (op == "ping") // order heartbeat
                        {
                            //LOG(INFO) << plaintext;

                            string pong = plaintext.replace(plaintext.find("ping"), 4, "pong");
                            p_ws->SendMsg(pong);

                            //LOG(INFO) << pong;
                        }
                        else if (op == "close")
                        {
                            LOG(INFO) << plaintext;
                        }
                        else if (op == "error")
                        {
                            LOG(ERROR) << plaintext;
                        }

                        else if (op == "auth")
                        {
                            LOG(INFO) << plaintext;
                        }
                        else if (op == "notify")
                        {
                            HandleSubCallbackFun(jdata["topic"].get<string>(), plaintext, jdata);
                        }
                        else if (op == "sub")
                        {
                            LOG(INFO) << plaintext;
                        }
                        else if (op == "unsub")
                        {
                            LOG(INFO) << plaintext;
                            string ch = jdata["topic"].get<string>();
                            if (sub_map_call_fun.find(ch) != sub_map_call_fun.end())
                            {
                                _call_back_fun fun = sub_map_call_fun[ch];
                                sub_map_call_fun.erase(ch);
                            }
                        }
                        else
                        {
                            LOG(INFO) << "WebSocket received unknow data:" << plaintext;
                        }
                    }
                    else if (jdata.contains("subbed")) // sub success reply
                    {
                        LOG(INFO) << plaintext;
                    }
                    else if (jdata.contains("unsubbed")) // unsub success reply
                    {
                        LOG(INFO) << plaintext;
                        string ch = jdata["topic"].get<string>();
                        if (sub_map_call_fun.find(ch) != sub_map_call_fun.end())
                        {
                            _call_back_fun fun = sub_map_call_fun[ch];
                            sub_map_call_fun.erase(ch);
                        }
                    }
                    else if (jdata.contains("ch")) // market sub reply data
                    {
                        HandleSubCallbackFun(jdata["ch"].get<string>(), plaintext, jdata);
                    }
                    else if (jdata.contains("rep")) // market request reply data
                    {
                        HandleReqCallbackFun(jdata["rep"].get<string>(), plaintext, jdata);
                    }
                    else if (jdata.contains("err-code")) // market request reply data
                    {
                        LOG(ERROR) << plaintext;
                    }
                    else
                    {
                        LOG(INFO) << "WebSocket received unknow data:" << plaintext;
                    }
                }

                void HandleSubCallbackFun(const string &ch, const string &data, const nlohmann::json &jdata)
                {
                    _call_back_fun fun = NULL;
                    if (sub_map_call_fun.find(ch) != sub_map_call_fun.end())
                    {
                        fun = sub_map_call_fun[ch];
                    }
                    else if (ch.substr(0, 7) == "orders." && sub_map_call_fun.find("orders.*") != sub_map_call_fun.end())
                    {
                        fun = sub_map_call_fun["orders.*"];
                    }
                    else if (ch.substr(0, 12) == "matchOrders." && sub_map_call_fun.find("matchOrders.*") != sub_map_call_fun.end())
                    {
                        fun = sub_map_call_fun["matchOrders.*"];
                    }
                    else if (ch.substr(0, 14) == "trigger_order." && sub_map_call_fun.find("trigger_order.*") != sub_map_call_fun.end())
                    {
                        fun = sub_map_call_fun["trigger_order.*"];
                    }
                    else if (ch.substr(ch.length() - 19) == ".liquidation_orders" && sub_map_call_fun.find("public.*.liquidation_orders") != sub_map_call_fun.end())
                    {
                        fun = sub_map_call_fun["public.*.liquidation_orders"];
                    }
                    else if (ch == "accounts" || ch == "positions")
                    {
                        string contract_code = jdata["data"][0]["contract_code"].get<string>();
                        stringstream str_buf;
                        str_buf << "{" << ch << "}.{" << contract_code << "}";
                        string full_ch = str_buf.str();
                        if (sub_map_call_fun.find(full_ch) != sub_map_call_fun.end())
                        {
                            fun = sub_map_call_fun[full_ch];
                        }
                        else if (sub_map_call_fun.find(ch + ".*") != sub_map_call_fun.end())
                        {
                            fun = sub_map_call_fun[ch + ".*"];
                        }
                    }

                    if (fun == NULL)
                    {
                        LOG(ERROR) << "no callback function to handle:" << data;
                        return;
                    }

                    fun(data);
                }

                void HandleReqCallbackFun(string ch, string data, const nlohmann::json &jdata)
                {
                    if (req_map_call_fun.find(ch) == req_map_call_fun.end())
                    {
                        LOG(ERROR) << "no callback function to handle:" << data;
                        return;
                    }
                    _call_back_fun fun = req_map_call_fun[ch];
                    if (fun == NULL)
                    {
                        LOG(ERROR) << "no callback function to handle:" << data;
                        return;
                    }
                    fun(data);
                }

                string host;
                string path;

                WebSocket *p_ws;
                string ak;
                string sk;

                map<string, _call_back_fun> sub_map_call_fun;
                map<string, _call_back_fun> req_map_call_fun;
            };
        } // namespace ws
    }     // namespace linear_swap
} // namespace huobi_futures
