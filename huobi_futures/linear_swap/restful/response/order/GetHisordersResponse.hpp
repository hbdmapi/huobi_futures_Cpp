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
                struct GetHisordersResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Order
                        {
                            int64_t order_id;

                            string order_id_str;

                            string symbol;

                            string contract_code;

                            int32_t lever_rate;

                            string direction;

                            string offset;

                            int32_t volume;

                            float price;

                            int64_t create_date;

                            int64_t update_time;

                            string order_source;

                            string order_price_type;

                            string margin_asset;

                            float margin_frozen;

                            float profit;

                            float trade_volume;

                            float trade_turnover;

                            float fee;

                            JS::Nullable<float> trade_avg_price;

                            int32_t status;

                            int32_t order_type;

                            string fee_asset;

                            JS::Nullable<string> liquidation_type;

                            string margin_mode;

                            string margin_account;

                            int32_t is_tpsl;

                            float real_profit;

                            JS_OBJ(order_id, order_id_str, symbol, contract_code, lever_rate, direction, offset, volume, price,
                                   create_date, update_time, order_source, order_price_type, margin_asset, margin_frozen, profit,
                                   trade_volume, trade_turnover, fee, trade_avg_price, status, order_type, fee_asset,
                                   liquidation_type, margin_mode, margin_account, is_tpsl, real_profit);
                        };

                        std::vector<Order> orders;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(orders, total_page, current_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures