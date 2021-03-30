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
                struct SubTradeDetailResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        int64_t id;

                        int64_t ts;

                        struct Data
                        {
                            float amount;

                            int64_t ts;

                            int64_t id;

                            float price;

                            string direction;

                            float quantity;

                            float trade_turnover;

                            JS_OBJ(amount, ts, id, price, direction, quantity, trade_turnover);
                        };

                        std::vector<Data> data;

                        JS_OBJ(id, ts, data);
                    };

                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
