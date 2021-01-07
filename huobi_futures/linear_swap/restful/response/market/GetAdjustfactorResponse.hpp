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
                struct GetAdjustfactorResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        std::optional<string> contract_code;

                        string margin_mode;

                        struct List
                        {
                            struct Ladders
                            {
                                int32_t min_size;

                                JS::Nullable<int32_t> max_size;

                                int32_t ladder;

                                float adjust_factor;

                                JS_OBJ(min_size, max_size, ladder, adjust_factor);
                            };

                            std::optional<int32_t> lever_rate;

                            std::vector<Ladders> ladders;

                            JS_OBJ(lever_rate, ladders);
                        };
                        std::vector<List> list;

                        JS_OBJ(symbol, contract_code, margin_mode, list);
                    };

                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
