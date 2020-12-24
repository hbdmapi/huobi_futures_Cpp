#pragma once

#include <string>
using std::string;

#include <ctime>
#include <sstream>

#include "huobi_futures/utils/Signer.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"

namespace huobi_futures
{
    namespace url_base
    {
        class PrivateUrlBuilder
        {
        public:
            PrivateUrlBuilder(const string &access_key, const string &secret_key, const string &host)
            {
                ak = access_key;
                sk = secret_key;
                this->host = host;
            }

            string Build(const string &method, const string &path)
            {
                time_t now;
                time(&now);
                return Build(method, path, now);
            }

            string Build(const string &method, const string &path, time_t time)
            {
                char pchar_time[sizeof "2011-10-08T07:07:09"];
                strftime(pchar_time, sizeof pchar_time, "%FT%T", gmtime(&time));

                stringstream para;
                para << "AccessKeyId=" << ak << "&SignatureMethod=HmacSHA256&SignatureVersion=2&Timestamp=" << HttpRequest::Instance().UrlEncode(pchar_time);

                string signature = utils::Signer::CreateSignature(method, host, path, para.str(), sk);

                string url = "https://" + host + path + "?" + para.str() + "&Signature=" + HttpRequest::Instance().UrlEncode(signature);

                return url;
            }

        private:
            string host;
            string ak;
            string sk;
        };
    } // namespace url_base
} // namespace huobi_futures