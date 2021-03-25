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
                struct GetHisordersExactResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Order
                        {
                            int64_t query_id;

                            int64_t order_id;

                            string order_id_str;

                            string symbol;

                            string contract_code;

                            string margin_mode;

                            string margin_account;

                            int32_t lever_rate;

                            string direction;

                            string offset;

                            int32_t volume;

                            float price;

                            int64_t create_date;

                            string order_source;

                            string order_price_type;

                            float margin_frozen;

                            float profit;

                            float real_profit;

                            float trade_volume;

                            float trade_turnover;

                            float fee;

                            JS::Nullable<float> trade_avg_price;

                            int32_t status;

                            int32_t order_type;

                            string fee_asset;

                            JS::Nullable<string> liquidation_type;

                            int32_t is_tpsl;

                            JS_OBJ(query_id, order_id, order_id_str, symbol, contract_code, margin_mode, margin_account,
                                   lever_rate, direction, offset, volume, price, create_date, order_source, order_price_type,
                                   margin_frozen, profit, real_profit, trade_volume, trade_turnover, fee, trade_avg_price,
                                   status, order_type, fee_asset, liquidation_type, is_tpsl);
                        };

                        std::vector<Order> orders;

                        int32_t remain_size;

                        JS::Nullable<int64_t> next_id;

                        JS_OBJ(orders, remain_size, next_id);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures