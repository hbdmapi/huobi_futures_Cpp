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
                struct GetAccountPositionSingleResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string margin_asset;

                        float margin_balance;

                        float margin_static;

                        float margin_position;

                        float margin_frozen;

                        float profit_real;

                        float profit_unreal;

                        float withdraw_available;

                        JS::Nullable<float> risk_rate;

                        string margin_mode;

                        string margin_account;

                        struct Positions
                        {
                            string symbol;

                            string contract_code;

                            float volume;

                            float available;

                            float frozen;

                            float cost_open;

                            float cost_hold;

                            float profit_unreal;

                            float profit_rate;

                            float profit;

                            string margin_asset;

                            float position_margin;

                            int32_t lever_rate;

                            string direction;

                            float last_price;

                            string margin_mode;

                            string margin_account;

                            JS_OBJ(symbol, contract_code, volume, available, frozen, cost_open, cost_hold, profit_unreal, profit_rate, profit, \
                                   margin_asset, position_margin, lever_rate, direction, last_price, margin_mode, margin_account);
                        };

                        std::optional<std::vector<Positions>> positions;

                        struct ContractDetail
                        {
                            string symbol;

                            string contract_code;

                            float margin_position;

                            float margin_frozen;

                            float margin_available;

                            float profit_unreal;

                            JS::Nullable<float> liquidation_price;

                            float lever_rate;

                            float adjust_factor;

                            JS_OBJ(symbol, contract_code, margin_position, margin_frozen, margin_available, liquidation_price, \
                                   lever_rate, adjust_factor);
                        };
                        std::optional<std::vector<ContractDetail>> contract_detail;

                        JS_OBJ(margin_asset, margin_balance, margin_static, margin_position, margin_frozen, profit_real, \
                               profit_unreal, withdraw_available, risk_rate, margin_mode, margin_account, positions, contract_detail);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
