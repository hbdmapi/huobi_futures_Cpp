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
        struct WSUnsubData
        {
            string unsub;

            string id;

            string data_type;

            string ToJson()
            {
                stringstream str_buf;
                str_buf << "{"
                        << "\"unsub\":\"" << unsub << "\",\"id\":\"" << id << "\"";
                if (!data_type.empty())
                {
                    str_buf << "\",\"data_type\":\"" << data_type << "\"";
                }
                str_buf << "}";

                return str_buf.str();
            }
        };
    } // namespace wsbase
} // namespace huobi_futures
