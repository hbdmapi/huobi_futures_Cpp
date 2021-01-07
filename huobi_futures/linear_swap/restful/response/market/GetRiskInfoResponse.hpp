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
                struct GetRiskInfoResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    int64_t ts;

                    struct Data
                    {
                        float estimated_clawback;

                        float insurance_fund;

                        string contract_code;

                        JS_OBJ(estimated_clawback, insurance_fund, contract_code);
                    };

                    std::optional<std::vector<Data>> data;

                    JS_OBJ(status, err_code, err_msg, data);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
