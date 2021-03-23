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
                struct GetTransferLimitResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        std::optional<string> symbol;

                        std::optional<string> contract_code;

                        string margin_mode;

                        string margin_account;

                        float transfer_in_max_each;

                        float transfer_in_min_each;

                        float transfer_out_max_each;

                        float transfer_out_min_each;

                        float transfer_in_max_daily;

                        float transfer_out_max_daily;

                        float net_transfer_in_max_daily;

                        float net_transfer_out_max_daily;

                        JS_OBJ(symbol, contract_code, margin_mode, margin_account, transfer_in_max_each, transfer_in_min_each, transfer_out_max_each,
                               transfer_out_min_each, transfer_in_max_daily, transfer_out_max_daily, net_transfer_in_max_daily, net_transfer_out_max_daily);
                    };

                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
