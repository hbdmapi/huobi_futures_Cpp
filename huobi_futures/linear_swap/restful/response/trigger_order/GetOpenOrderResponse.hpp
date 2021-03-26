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
                struct GetOpenOrderResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Order
                        {
                            string symbol;

                            string contract_code;

                            string trigger_type;

                            float volume;

                            int32_t order_type;

                            string direction;

                            std::optional<string> offset;

                            std::optional<int32_t> lever_rate;

                            int64_t order_id;

                            string order_id_str;

                            string order_source;

                            float trigger_price;

                            float order_price;

                            int64_t created_at;

                            string order_price_type;

                            string status;

                            string margin_mode;

                            string margin_account;

                            std::optional<string> tpsl_order_type;

                            std::optional<string> source_order_id;

                            std::optional<string> relation_tpsl_order_id;

                            JS_OBJ(symbol, contract_code, trigger_type, volume, order_type, direction, offset, lever_rate,
                                   order_id, order_id_str, order_source, trigger_price, order_price, created_at, order_price_type,
                                   status, margin_mode, margin_account, tpsl_order_type, source_order_id, relation_tpsl_order_id);
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
            } // namespace response_trigger_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures