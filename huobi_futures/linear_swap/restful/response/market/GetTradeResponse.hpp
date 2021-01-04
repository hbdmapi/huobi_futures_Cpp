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
                struct GetTradeResponse
                {
                    std::optional<string> ch;

                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Tick
                    {
                        int64_t id;

                        struct Data
                        {
                            string amount;

                            string direction;

                            int64_t id;

                            string price;

                            int64_t ts;

                            JS_OBJ(amount, direction, id, price, ts);
                        };
                        JS::Nullable<std::vector<Data>> data;

                        int64_t ts;

                        JS_OBJ(id, data, ts);
                    };
                    Tick tick;

                    int64_t ts;

                    JS_OBJ(ch, status, err_code, err_msg, tick, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
