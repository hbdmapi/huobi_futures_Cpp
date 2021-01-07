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
        namespace restful
        {
            namespace response_market
            {
                struct GetLiquidationOrdersResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Orders
                        {
                            string symbol;

                            string contract_code;

                            int64_t created_at;

                            string direction;

                            string offset;

                            float price;

                            int64_t volume;

                            float amount;

                            float trade_turnover;

                            JS_OBJ(symbol, contract_code, created_at, direction, offset, price, volume, amount, trade_turnover);
                        };
                        std::vector<Orders> orders;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(orders, total_page, current_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
