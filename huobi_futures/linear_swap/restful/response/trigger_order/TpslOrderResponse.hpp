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
                struct TpslOrderResponse
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

                            JS_OBJ(order_id, order_id_str);
                        };
                        std::optional<Order> tp_order;

                        std::optional<Order> sl_order;

                        JS_OBJ(tp_order, sl_order);

                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_trigger_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
