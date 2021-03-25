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
                struct GetOrderDetailResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        int32_t lever_rate;

                        string direction;

                        string offset;

                        int32_t volume;

                        float price;

                        int64_t created_at;

                        string canceled_at;

                        string order_source;

                        string order_price_type;

                        string margin_asset;

                        float margin_frozen;

                        float profit;

                        float instrument_price;

                        float final_interest;

                        float adjust_value;

                        float fee;

                        string fee_asset;

                        string liquidation_type;

                        int64_t order_id;

                        string order_id_str;

                        JS::Nullable<int64_t> client_order_id;

                        int32_t order_type;

                        int32_t status;

                        JS::Nullable<float> trade_avg_price;

                        float trade_turnover;

                        int32_t trade_volume;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        string margin_mode;

                        string margin_account;

                        int32_t is_tpsl;

                        float real_profit;

                        struct Trade
                        {
                            string id;

                            int64_t trade_id;

                            float trade_price;

                            float trade_volume;

                            float trade_turnover;

                            float trade_fee;

                            string role;

                            int64_t created_at;

                            float real_profit;

                            float profit;

                            JS_OBJ(id, trade_id, trade_price, trade_volume, trade_turnover, trade_fee, role, created_at, real_profit, profit);
                        };
                        std::vector<Trade> trades;

                        JS_OBJ(symbol, contract_code, lever_rate, direction, offset, volume, price, created_at, canceled_at,
                               order_source, order_price_type, margin_asset, margin_frozen, profit, instrument_price, final_interest,
                               adjust_value, fee, fee_asset, liquidation_type, order_id, order_id_str, client_order_id, order_type, status,
                               trade_avg_price, trade_turnover, trade_volume, total_page, current_page, total_size, margin_mode, margin_account,
                               is_tpsl, real_profit, trades);
                    };

                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
