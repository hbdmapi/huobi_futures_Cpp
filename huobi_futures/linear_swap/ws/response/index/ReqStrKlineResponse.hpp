#pragma once

#include <string>
using std::string;

#include "huobi_futures/json_struct/json_struct.h"
#include <vector>
#include <optional>

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace ws
        {
            namespace response_index
            {
                struct ReqStrKlineResponse
                {
                    string rep;

                    string status;

                    string id;

                    int64_t wsid;

                    int64_t ts;

                    struct Data
                    {
                        int64_t id;

                        string vol;

                        string count;

                        string open;

                        string close;

                        string low;

                        string high;

                        string amount;

                        JS_OBJ(id, vol, count, open, close, low, high, amount);
                    };

                    std::vector<Data> data;

                    JS_OBJ(rep, status, id, wsid, data, ts);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
