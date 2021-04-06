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
            namespace response_notify
            {
                struct SubLiquidationOrdersResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string direction;

                        string offset;

                        float volume;

                        float amount;

                        float trade_turnover;

                        float price;

                        int64_t created_at;

                        JS_OBJ(symbol, contract_code, direction, offset, volume, amount, trade_turnover, price, created_at);
                    };

                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, data);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
