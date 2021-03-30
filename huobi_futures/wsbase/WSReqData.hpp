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
        struct WSReqData
        {
            string req;

            string id;

            int64_t from;

            int64_t to;

            int32_t size;

            WSReqData()
            {
                from = 0;
                to = 0;
                size = 0;
            }

            string ToJson()
            {
                stringstream str_buf;
                str_buf << "{"
                        << "\"req\":\"" << req << "\",\"id\":\"" << id << "\"";
                if (from != 0)
                {
                    str_buf << ",\"from\":" << from;
                }
                if (to != 0)
                {
                    str_buf << ",\"to\":" << to;
                }
                if (size != 0)
                {
                    str_buf << ",\"size\":" << size;
                }
                str_buf << "}";

                return str_buf.str();
            }
        };
    } // namespace wsbase
} // namespace huobi_futures
