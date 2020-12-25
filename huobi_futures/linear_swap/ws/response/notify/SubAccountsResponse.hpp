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
        namespace ws
        {
            namespace response_notify
            {
                struct SubAccountsResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    string uid;

                    string event;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string margin_asset;

                        float margin_balance;

                        float margin_static;

                        float margin_position;

                        float margin_frozen;

                        float margin_available;

                        float profit_real;

                        float profit_unreal;

                        float withdraw_available;

                        float risk_rate;

                        float liquidation_price;

                        float lever_rate;

                        float adjust_factor;

                        string margin_mode;

                        string margin_account;

                        JS_OBJ(symbol, contract_code, margin_asset, margin_balance, margin_static, margin_position,
                               margin_frozen, margin_available, profit_real, profit_unreal, withdraw_available, risk_rate,
                               liquidation_price, lever_rate, adjust_factor, margin_mode, margin_account);
                    };

                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, uid, event, data);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
