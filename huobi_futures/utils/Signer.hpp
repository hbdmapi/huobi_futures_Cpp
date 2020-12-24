#pragma once

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <time.h>
#include <openssl/hmac.h>

#include "huobi_futures/utils/base64.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"

namespace huobi_futures
{
    namespace utils
    {
        class Signer
        {
        public:
            static string CreateSignature(const string &method, const string &host, const string &path, const string &para, const string& secret_key)
            {
                if (secret_key.empty())
                {
                    LOG(ERROR) << "secret_key key are required";
                }

                stringstream msg_buf;
                msg_buf << method << "\n"
                        << host << "\n"
                        << path << "\n"
                        << para;
                string msg = msg_buf.str();

                unsigned char hash[1024];
                unsigned int len = 1024;

                HMAC_CTX *pctx = HMAC_CTX_new();
                HMAC_Init_ex(pctx, secret_key.c_str(), secret_key.length(), EVP_sha256(), NULL);
                HMAC_Update(pctx, (unsigned char *)&msg[0], msg.length());
                HMAC_Final(pctx, hash, &len);
                HMAC_CTX_free(pctx);

                string code;
                code = base64_encode(hash, 32);

                return code;
            }
        };
    } // namespace utils
} // namespace huobi_futures
