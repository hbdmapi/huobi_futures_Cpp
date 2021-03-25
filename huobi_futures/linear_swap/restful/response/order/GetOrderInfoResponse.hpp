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
            namespace response_order
            {
                struct GetOrderInfoResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        int32_t volume;

                        float price;

                        string order_price_type;

                        string direction;

                        string offset;

                        int32_t lever_rate;

                        int64_t order_id;

                        string order_id_str;

                        JS::Nullable<int64_t> client_order_id;

                        int64_t created_at;

                        int32_t trade_volume;

                        float trade_turnover;

                        float fee;

                        JS::Nullable<float> trade_avg_price;

                        string margin_asset;

                        float margin_frozen;

                        float profit;

                        int32_t status;

                        int32_t order_type;

                        string order_source;

                        string fee_asset;

                        string liquidation_type;

                        int64_t canceled_at;

                        string margin_account;

                        string margin_mode;

                        int32_t is_tpsl;

                        float real_profit;

                        JS_OBJ(symbol, contract_code, volume, price, order_price_type, direction, offset, lever_rate,
                               order_id, order_id_str, client_order_id, created_at, trade_volume, trade_turnover, fee,
                               trade_avg_price, margin_asset, margin_frozen, profit, status, order_type, order_source,
                               fee_asset, liquidation_type, canceled_at, margin_account, margin_mode, is_tpsl, real_profit);
                    };

                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
