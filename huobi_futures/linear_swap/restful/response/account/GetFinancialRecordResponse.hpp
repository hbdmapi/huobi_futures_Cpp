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
                struct GetFinancialRecordResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Financial
                        {
                            int64_t id;

                            int64_t ts;

                            string asset;

                            string contract_code;

                            string margin_account;

                            string face_margin_account;

                            int64_t type;

                            float amount;

                            JS_OBJ(id, ts, asset, contract_code, margin_account, face_margin_account, type, amount);
                        };

                        std::vector<Financial> financial_record;

                        int32_t current_page;

                        int32_t total_page;

                        int32_t total_size;

                        JS_OBJ(financial_record, current_page, total_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
