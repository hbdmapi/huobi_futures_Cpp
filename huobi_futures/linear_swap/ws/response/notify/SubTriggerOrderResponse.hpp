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
                struct SubTriggerOrderResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    string event;

                    string uid;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string trigger_type;

                        float volume;

                        int32_t order_type;

                        string direction;

                        string offset;

                        int32_t lever_rate;

                        int64_t order_id;

                        string order_id_str;

                        string relation_order_id;

                        string order_price_type;

                        int32_t status;

                        string order_source;

                        float trigger_price;

                        JS::Nullable<float> triggered_price;

                        float order_price;

                        int64_t created_at;

                        int64_t triggered_at;

                        int64_t order_insert_at;

                        int64_t canceled_at;

                        string margin_mode;

                        string margin_account;

                        JS::Nullable<int32_t> fail_code;

                        JS::Nullable<string> fail_reason;

                        JS_OBJ(symbol, contract_code, trigger_type, volume, order_type,
                               direction, offset, lever_rate, order_id, order_id_str,
                               relation_order_id, order_price_type, status, order_source,
                               trigger_price, triggered_price, order_price, created_at,
                               triggered_at, order_insert_at, canceled_at, margin_mode,
                               margin_account, fail_code, fail_reason);
                    };

                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, uid, event, data);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
