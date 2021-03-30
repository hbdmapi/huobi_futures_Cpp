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
                struct SubMarketDetailResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        int64_t id;

                        int64_t mrid;

                        float open;

                        float close;

                        float high;

                        float low;

                        float amount;

                        float vol;

                        float trade_turnover;

                        float count;

                        std::vector<float> ask;

                        std::vector<float> bid;

                        JS_OBJ(id, mrid, open, close, high, low, amount, vol, trade_turnover, count, ask, bid);
                    };

                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
