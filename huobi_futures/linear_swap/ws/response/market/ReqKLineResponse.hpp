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
            namespace response_market
            {
                struct ReqKLineResponse
                {
                    string rep;

                    string status;

                    string id;

                    int64_t wsid;

                    struct Data
                    {
                        int64_t id;

                        float vol;

                        float count;

                        float open;

                        float close;

                        float low;

                        float high;

                        float amount;

                        float trade_turnover;

                        JS_OBJ(id, vol, count, open, close, low, high, amount, trade_turnover);
                    };

                    std::vector<Data> data;

                    JS_OBJ(rep, status, id, wsid, data);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
