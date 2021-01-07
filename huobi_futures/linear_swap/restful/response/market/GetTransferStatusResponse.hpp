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
                struct GetTransferStatusResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        int32_t transfer_in;

                        int32_t transfer_out;

                        int32_t master_transfer_sub;

                        int32_t sub_transfer_master;

                        int32_t master_transfer_sub_inner_in;

                        int32_t master_transfer_sub_inner_out;

                        int32_t sub_transfer_master_inner_in;

                        int32_t sub_transfer_master_inner_out;

                        int32_t transfer_inner_in;

                        int32_t transfer_inner_out;

                        string margin_mode;

                        string margin_account;

                        JS_OBJ(transfer_in, transfer_out, master_transfer_sub, sub_transfer_master, \
                              master_transfer_sub_inner_in, master_transfer_sub_inner_out, sub_transfer_master_inner_in, sub_transfer_master_inner_out, \
                              transfer_inner_in, transfer_inner_out, margin_mode, margin_account);
                    };

                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
