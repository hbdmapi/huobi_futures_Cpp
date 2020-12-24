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
                struct GetHisFundingRateResponse
                {
                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct InnerDate
                        {
                            string symbol;

                            string contract_code;

                            string fee_asset;

                            string funding_time;

                            string funding_rate;

                            string realized_rate;

                            string avg_premium_index;

                            JS_OBJ(symbol, contract_code, fee_asset, funding_time, funding_rate, realized_rate, avg_premium_index);
                        };

                        std::vector<InnerDate> data;

                        int total_page;

                        int current_page;

                        int total_size;

                        JS_OBJ(data, total_page, current_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
