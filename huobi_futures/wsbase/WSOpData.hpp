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
        struct WSOpData
        {
            string op;

            string cid;

            string topic;

            string ToJson()
            {
                stringstream str_buf;
                str_buf << "{"
                        << "\"op\":\"" << op << "\"";
                if (cid != "")
                {
                    str_buf << ",\"cid\":\"" << cid << "\"";
                }
                str_buf << ",\"topic\":\"" << topic << "\"}";

                return str_buf.str();
            }
        };
    } // namespace wsbase
} // namespace huobi_futures
