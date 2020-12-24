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
                struct PlaceOrderResponse
                {
                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        int64_t order_id;

                        std::optional<int64_t> client_order_id;

                        string order_id_str;

                        JS_OBJ(order_id, client_order_id, order_id_str);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
