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
                struct GetInsurancefundResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    int64_t ts;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        struct Tick
                        {
                            float insurance_fund;

                            int64_t ts;

                            JS_OBJ(insurance_fund, ts);
                        };

                        std::vector<Tick> tick;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(symbol, contract_code, tick, total_page, current_page, total_size);
                    };

                    std::optional<Data> data;

                    JS_OBJ(status, err_code, err_msg, data);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
