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

            WSReqData()
            {
                from = -1;
                to = -1;
            }

            string ToJson()
            {
                stringstream str_buf;
                str_buf << "{"
                        << "\"req\":\"" << req << "\",\"id\":\"" << id
                        << "\",\"from\":" << from << ",\"to\":" << to << "}";

                return str_buf.str();
            }
        };
    } // namespace wsbase
} // namespace huobi_futures
