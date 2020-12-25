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
                struct SubOrdersResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    string uid;

                    string symbol;

                    string contract_code;

                    float volume;

                    float price;

                    string order_price_type;

                    string direction;

                    string offset;

                    int32_t status;

                    int32_t lever_rate;

                    int64_t order_id;

                    string order_id_str;

                    JS::Nullable<int64_t> client_order_id;

                    string order_source;

                    int32_t order_type;

                    int64_t created_at;

                    float trade_volume;

                    float trade_turnover;

                    float fee;

                    float trade_avg_price;

                    string margin_asset;

                    float margin_frozen;

                    float profit;

                    float liquidation_type;

                    int64_t canceled_at;

                    string fee_asset;

                    string margin_mode;

                    string margin_account;

                    struct Trade
                    {
                        string id;

                        int64_t trade_id;

                        float trade_volume;

                        float trade_price;

                        float trade_fee;

                        float trade_turnover;

                        int64_t created_at;

                        string role;

                        string fee_asset;

                        JS_OBJ(id, trade_id, trade_volume, trade_price, trade_fee, trade_turnover, created_at, role, fee_asset);
                    };

                    std::vector<Trade> trade;

                    JS_OBJ(op, topic, ts, uid, symbol, contract_code, volume, price, order_price_type,
                           direction, offset, status, lever_rate, order_id, order_id_str, client_order_id,
                           order_source, order_type, created_at, trade_volume, trade_turnover, fee,
                           trade_avg_price, margin_asset, margin_frozen, profit, liquidation_type, canceled_at,
                           fee_asset, margin_mode, margin_account, trade);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
