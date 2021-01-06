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
                struct GetHisTradeResponse
                {
                    std::optional<string> ch;

                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    int64_t ts;

                    struct HisTrade
                    {
                        int64_t id;

                        int64_t ts;

                        struct Data
                        {
                            float amount;

                            string direction;

                            int64_t id;

                            float price;

                            int64_t ts;

                            JS_OBJ(amount, direction, id, price, ts);
                        };
                        std::vector<Data> data;

                        JS_OBJ(id, ts, data);
                    };
                    std::optional<HisTrade> tick;

                    JS_OBJ(ch, status, err_code, err_msg, ts, tick);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
