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
                struct GetFinancialRecordExactResponse
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

                            int32_t type;

                            float amount;

                            JS_OBJ(id, ts, asset, contract_code, margin_account, face_margin_account, type, amount);
                        };

                        JS::Nullable<std::vector<Financial>> financial_record;

                        int32_t remain_size;

                        JS::Nullable<int64_t> next_id;

                        JS_OBJ(financial_record, remain_size, next_id);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
