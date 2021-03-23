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
                struct GetSubAccountInfoListResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Sub
                        {
                            string sub_uid;

                            struct AccountInfo
                            {
                                std::optional<string> symbol;

                                std::optional<string> contract_code;

                                string margin_asset;

                                float margin_balance;

                                std::optional<JS::Nullable<float>> liquidation_price;

                                JS::Nullable<float> risk_rate;

                                string margin_mode;

                                string margin_account;

                                JS_OBJ(symbol, contract_code, margin_account, margin_mode, margin_asset, margin_balance, liquidation_price, risk_rate);
                            };

                            std::vector<AccountInfo> account_info_list;

                            JS_OBJ(sub_uid, account_info_list);
                        };

                        std::vector<Sub> sub_list;

                        int32_t current_page;

                        int32_t total_page;

                        int32_t total_size;

                        JS_OBJ(sub_list, current_page, total_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
