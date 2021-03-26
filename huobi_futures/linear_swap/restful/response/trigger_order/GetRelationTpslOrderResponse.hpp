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
            namespace response_trigger_order
            {
                struct GetRelationTpslOrderResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string margin_mode;

                        string margin_account;

                        float volume;

                        float price;

                        string order_price_type;

                        string direction;

                        string offset;

                        int32_t lever_rate;

                        int64_t order_id;

                        string order_id_str;

                        JS::Nullable<int64_t> client_order_id;

                        int64_t created_at;

                        float trade_volume;

                        float trade_turnover;

                        float fee;

                        float trade_avg_price;

                        float margin_frozen;

                        float profit;

                        int32_t status;

                        int32_t order_type;

                        string order_source;

                        string fee_asset;

                        int64_t canceled_at;

                        struct TpslOrderInfo
                        {
                            float volume;

                            string tpsl_order_type;

                            string direction;

                            int64_t order_id;

                            string order_id_str;

                            string trigger_type;

                            float trigger_price;

                            float order_price;

                            int64_t created_at;

                            string order_price_type;

                            int32_t status;

                            string relation_tpsl_order_id;

                            int64_t canceled_at;

                            int32_t fail_code;

                            string fail_reason;

                            float triggered_price;

                            string relation_order_id;

                            JS_OBJ(volume, tpsl_order_type, direction, order_id, order_id_str, trigger_type,
                                   trigger_price, order_price, created_at, order_price_type, status,
                                   relation_tpsl_order_id, canceled_at, fail_code, fail_reason, triggered_price,
                                   relation_order_id);
                        };
                        std::vector<std::optional<TpslOrderInfo>> tpsl_order_info;

                        JS_OBJ(symbol, contract_code, margin_mode, margin_account, volume,
                               price, order_price_type, direction, offset, lever_rate, order_id,
                               order_id_str, client_order_id, created_at, trade_volume,
                               trade_turnover, fee, trade_avg_price, margin_frozen, profit,
                               status, order_type, order_source, fee_asset, canceled_at, tpsl_order_info);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_trigger_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
