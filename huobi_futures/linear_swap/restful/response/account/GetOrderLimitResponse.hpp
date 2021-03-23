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
            namespace response_account
            {
                struct GetOrderLimitResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string order_price_type;

                        struct Limit
                        {
                            string symbol;

                            string contract_code;

                            float open_limit;

                            float close_limit;

                            JS_OBJ(symbol, contract_code, open_limit, close_limit);
                        };

                        std::vector<Limit> list;

                        JS_OBJ(order_price_type, list);
                    };

                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
