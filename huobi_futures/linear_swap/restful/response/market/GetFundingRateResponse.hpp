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
                struct GetFundingRateResponse
                {
                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string fee_asset;

                        string funding_time;

                        string funding_rate;

                        string estimated_rate;

                        string next_funding_time;

                        JS_OBJ(symbol, contract_code, fee_asset, funding_time, funding_rate, estimated_rate, next_funding_time);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(ch, status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
