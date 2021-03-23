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
                struct GetSubAccountListResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        int64_t sub_uid;

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

                            JS_OBJ(symbol, contract_code, margin_asset, margin_balance, liquidation_price, risk_rate, margin_mode, margin_account);
                        };

                        std::vector<AccountInfo> list;

                        JS_OBJ(sub_uid, list);
                    };
                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
