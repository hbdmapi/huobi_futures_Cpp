#pragma once

#include <string>
using std::string;

#include "huobi_futures/json_struct/json_struct.h"
#include <vector>
#include <optional>

#include <sstream>
using std::stringstream;

namespace huobi_futures
{
    namespace wsbase
    {
        struct WSAuthData
        {
            const string op = "auth";

            const string type = "api";

            string cid;

            string AccessKeyId;

            const string SignatureMethod = "HmacSHA256";

            const string SignatureVersion = "2";

            string Timestamp;

            string Signature;

            string ticket;

            string ToJson()
            {
                stringstream str_buf;
                str_buf << "{"
                        << "\"op\":\"" << op << "\",\"type\":\"" << type << "\",\"AccessKeyId\":\"" << AccessKeyId
                        << "\",\"SignatureMethod\":\"" << SignatureMethod << "\",\"SignatureVersion\":\"" << SignatureVersion
                        << "\",\"Timestamp\":\"" << Timestamp << "\",\"Signature\":\"" << Signature << "\"";
                if (!cid.empty())
                {
                    str_buf << "\",\"cid\":\"" << cid << "\"";
                }
                if (!ticket.empty())
                {
                    str_buf << "\",\"ticket\":\"" << ticket << "\"";
                }
                str_buf << "}";

                return str_buf.str();
            }
        };
    } // namespace wsbase
} // namespace huobi_futures
