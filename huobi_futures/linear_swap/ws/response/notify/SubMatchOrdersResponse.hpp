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
                struct SubMatchOrdersResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    string uid;

                    string symbol;

                    string contract_code;

                    int32_t status;

                    int64_t order_id;

                    string order_id_str;

                    JS::Nullable<int64_t> client_order_id;

                    int32_t order_type;

                    float trade_volume;

                    float volume;

                    string direction;

                    string offset;

                    int32_t lever_rate;

                    float price;

                    int64_t created_at;

                    string order_source;

                    string order_price_type;

                    string margin_mode;

                    string margin_account;

                    int64_t is_tpsl;

                    struct Trade
                    {
                        int64_t trade_id;

                        string id;

                        float trade_volume;

                        float trade_price;

                        float trade_turnover;

                        int64_t created_at;

                        string role;

                        JS_OBJ(trade_id, id, trade_volume, trade_price, trade_turnover, created_at, role);
                    };

                    std::vector<Trade> trade;

                    JS_OBJ(op, topic, ts, uid, symbol, contract_code, status, order_id,
                           order_id_str, client_order_id, order_type, trade_volume, volume,
                           direction, offset, lever_rate, price, created_at, order_source,
                           order_price_type, margin_mode, margin_account, is_tpsl, trade);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
