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
                struct GetOpenOrderResponse
                {
                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Order
                        {
                            string symbol;

                            string contract_code;

                            int32_t volume;

                            double price;

                            string order_price_type;

                            int32_t order_type;

                            string direction;

                            string offset;

                            int32_t lever_rate;

                            int64_t order_id;

                            string order_id_str;

                            JS::Nullable<int64_t> client_order_id;

                            int64_t created_at;

                            double trade_volume;

                            double trade_turnover;

                            double fee;

                            string fee_asset;

                            JS::Nullable<double> trade_avg_price;

                            double margin_frozen;

                            string margin_asset;

                            double profit;

                            int32_t status;

                            string order_source;

                            JS::Nullable<string> liquidation_type;

                            JS::Nullable<int64_t> canceled_at;

                            string margin_mode;

                            string margin_account;

                            JS_OBJ(symbol, contract_code, volume, price, order_price_type, order_type, direction, offset, \
                                    lever_rate, order_id, order_id_str, client_order_id, created_at, trade_volume, \
                                    trade_turnover, fee, fee_asset, trade_avg_price, margin_frozen, margin_asset, profit, \
                                    status, order_source, liquidation_type, canceled_at, margin_mode, margin_account);
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