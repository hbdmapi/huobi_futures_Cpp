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
                struct GetMasterSubTransferRecordResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Transfer
                        {
                            int64_t id;

                            int64_t ts;

                            string asset;

                            string margin_account;

                            string from_margin_account;

                            string to_margin_account;

                            string sub_uid;

                            string sub_account_name;

                            int32_t transfer_type;

                            float amount;

                            JS_OBJ(id, ts, asset, margin_account, from_margin_account, to_margin_account, sub_uid, sub_account_name, transfer_type, amount);
                        };

                        std::vector<Transfer> transfer_record;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(transfer_record, total_page, current_page, total_size);
                    };

                    std::optional<JS::Nullable<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
