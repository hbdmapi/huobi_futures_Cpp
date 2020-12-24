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
                struct SubKLineResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        int64_t id;

                        int64_t mrid;

                        float vol;

                        float count;

                        float open;

                        float close;

                        float low;

                        float high;

                        float amount;

                        float trade_turnover;

                        JS_OBJ(id, mrid, vol, count, open, close, low, high, amount, trade_turnover);
                    };
                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures