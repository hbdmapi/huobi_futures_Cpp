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
                struct GetAccountInfoResponse
                {
                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        std::optional<string> symbol;

                        std::optional<string> contract_code;

                        string margin_asset;

                        float margin_balance;

                        float margin_static;

                        float margin_position;

                        float margin_frozen;

                        std::optional<float> margin_available;

                        float profit_real;

                        float profit_unreal;

                        float withdraw_available;

                        JS::Nullable<float> risk_rate;

                        std::optional<JS::Nullable<float>>liquidation_price;

                        std::optional<float> lever_rate;

                        std::optional<float> adjust_factor;

                        string margin_mode;

                        string margin_account;

                        struct ContractDetail
                        {
                            string symbol;
                            string contract_code;
                            float margin_position;
                            float margin_frozen;
                            float margin_available;
                            float profit_unreal;
                            JS::Nullable<float> liquidation_price;
                            int32_t lever_rate;
                            float adjust_factor;

                            JS_OBJ(symbol, contract_code, margin_position, margin_frozen, margin_available, profit_unreal,
                                   liquidation_price, lever_rate, adjust_factor);
                        };
                        std::optional<std::vector<ContractDetail>> contract_detail;

                        JS_OBJ(symbol, contract_code, margin_asset, margin_balance, margin_static, margin_position, margin_frozen,
                               margin_available, profit_real, profit_unreal, withdraw_available, risk_rate, liquidation_price,
                               lever_rate, adjust_factor, margin_mode, margin_account, contract_detail);
                    };
                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
