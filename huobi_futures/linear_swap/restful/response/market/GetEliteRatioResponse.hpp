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
                struct GetEliteRatioResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        struct List
                        {
                            float buy_ratio;

                            float sell_ratio;

                            std::optional<float> locked_ratio;

                            int64_t ts;

                            JS_OBJ(buy_ratio, sell_ratio, locked_ratio, ts);
                        };

                        std::vector<List> list;

                        JS_OBJ(symbol, contract_code, list);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
