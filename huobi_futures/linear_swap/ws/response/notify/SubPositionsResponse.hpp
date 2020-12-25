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
                struct SubPositionsResponse
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

                        float volume;

                        float available;

                        float frozen;

                        float cost_open;

                        float cost_hold;

                        float profit_unreal;

                        float profit_rate;

                        float profit;

                        float position_margin;

                        int32_t lever_rate;

                        string direction;

                        float last_price;

                        string margin_asset;

                        string margin_mode;

                        string margin_account;

                        JS_OBJ(symbol, contract_code, volume, available, frozen, cost_open, cost_hold,
                               profit_unreal, profit_rate, profit, position_margin, lever_rate, direction,
                               last_price, margin_asset, margin_mode, margin_account);
                    };
                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, uid, event);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures