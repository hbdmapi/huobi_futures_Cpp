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
                struct GetPositionInfoResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
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

                        JS_OBJ(symbol, contract_code, volume, available, frozen, cost_open, cost_hold, profit_unreal, profit_rate, profit,\
                               margin_asset, position_margin, lever_rate, direction, last_price, margin_mode, margin_account);
                    };
                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures