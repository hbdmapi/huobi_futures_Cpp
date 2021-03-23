#pragma once

#include <curl/curl.h>

#include <string>
using std::string;

#include <glog/logging.h>
#include "huobi_futures/json_struct/json_struct.h"

#include <mutex>

namespace huobi_futures
{
    namespace url_base
    {
        class HttpRequest
        {
        public:
            virtual ~HttpRequest()
            {
                curl_easy_cleanup(curl);
                curl_global_cleanup();
            }

            static HttpRequest &Instance()
            {
                return HttpRequest::instance;
            }

            template <typename T>
            std::shared_ptr<T> Get(const string &url)
            {
                std::unique_lock<std::mutex> lck (mtx);

                LOG(INFO) << "get:" << url;

                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
                curl_slist *plist = curl_slist_append(NULL, "Content-Type:application/x-www-form-urlencoded");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, plist);

                string sBuffer;
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sBuffer);

                CURLcode res = curl_easy_perform(curl);
                if (res != CURLE_OK)
                {
                    LOG(ERROR) << "curl_easy_perform error:" << curl_easy_strerror(res);
                }

                std::shared_ptr<T> pObj = std::make_shared<T>();
                JS::ParseContext parseContext(sBuffer);
                parseContext.allow_unnasigned_required_members = false;

                if (parseContext.parseTo(*pObj) != JS::Error::NoError)
                {
                    std::string errorStr = parseContext.makeErrorString();
                    LOG(ERROR) << "Error parsing struct"
                               << errorStr;
                    LOG(ERROR) << sBuffer;
                    return NULL;
                }
                return pObj;
            }

            template <typename T>
            std::shared_ptr<T> Post(const string &url, const string &body = "")
            {
                std::unique_lock<std::mutex> lck (mtx);

                LOG(INFO) << "post:" << url << "\n"
                          << body;

                curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

                curl_easy_setopt(curl, CURLOPT_POST, 1);
                curl_slist *plist = curl_slist_append(NULL, "Content-Type:application/json;charset=UTF-8");
                curl_easy_setopt(curl, CURLOPT_HTTPHEADER, plist);

                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());

                string sBuffer;
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &sBuffer);

                CURLcode res = curl_easy_perform(curl);
                if (res != CURLE_OK)
                {
                    LOG(ERROR) << "curl_easy_perform error:" << curl_easy_strerror(res);
                }
                //LOG(INFO) << sBuffer;

                std::shared_ptr<T> pObj = std::make_shared<T>();
                JS::ParseContext parseContext(sBuffer);
                parseContext.allow_unnasigned_required_members = false;

                if (parseContext.parseTo(*pObj) != JS::Error::NoError)
                {
                    std::string errorStr = parseContext.makeErrorString();
                    LOG(ERROR) << "Error parsing struct:\n"
                               << sBuffer;
                    return NULL;
                }
                return pObj;
            }

            string UrlEncode(const string &data)
            {
                char *output = curl_easy_escape(curl, data.c_str(), data.length());
                string result(output);
                curl_free(output);

                return result;
            }

        private:
            static size_t callback_func(void *input, size_t uSize, size_t uCount, void *avg)
            {
                size_t uLen = uSize * uCount;
                std::string &sBuffer = *reinterpret_cast<std::string *>(avg);
                sBuffer.append(reinterpret_cast<const char *>(input), uLen);
                return uLen;
            }

            HttpRequest()
            {
                CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
                if (res != CURLE_OK)
                {
                    LOG(ERROR) << "curl_global_init error:" << curl_easy_strerror(res);
                }

                curl = curl_easy_init();
                if (curl == NULL)
                {
                    LOG(ERROR) << "curl_easy_init error.";
                }
                curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20);

                curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback_func);
            }

            static HttpRequest instance;
            CURL *curl = NULL;
            std::mutex mtx;
        };

        HttpRequest HttpRequest::instance;

    } // namespace url_base
} // namespace huobi_futures