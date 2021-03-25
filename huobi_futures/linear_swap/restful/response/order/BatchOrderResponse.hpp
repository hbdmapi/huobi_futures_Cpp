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
                struct BatchOrderResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Error
                        {
                            int32_t index;

                            int32_t err_code;

                            string err_msg;
                            
                            JS_OBJ(index, err_code, err_msg);
                        };
                        std::vector<Error> errors;

                        struct Success
                        {
                            int32_t index;

                            int64_t order_id;

                            string order_id_str;

                            std::optional<string> client_order_id;
                            
                            JS_OBJ(index, order_id, order_id_str, client_order_id);
                        };
                        std::vector<Success> success;

                        JS_OBJ(errors, success);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
