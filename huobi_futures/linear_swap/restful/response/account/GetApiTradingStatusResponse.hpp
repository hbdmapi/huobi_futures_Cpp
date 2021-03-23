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
            namespace response_account
            {
                struct GetApiTradingStatusResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        int32_t is_disable;

                        string order_price_types;

                        string disable_reason;

                        int64_t disable_interval;

                        int64_t recovery_time;

                        struct Cor
                        {
                            int64_t orders_threshold;

                            int64_t orders;

                            int64_t invalid_cancel_orders;

                            float cancel_ratio_threshold;

                            float cancel_ratio;

                            int32_t is_trigger;

                            int32_t is_active;

                            JS_OBJ(orders_threshold, orders, invalid_cancel_orders, cancel_ratio_threshold, cancel_ratio, is_trigger, is_active);
                        };

                        Cor COR;

                        struct Tdn
                        {
                            int64_t disables_threshold;

                            int64_t disables;

                            int32_t is_trigger;

                            int32_t is_active;

                            JS_OBJ(disables_threshold, disables, is_trigger, is_active);
                        };

                        Tdn TDN;

                        JS_OBJ(is_disable, order_price_types, disable_reason, disable_interval, recovery_time, COR, TDN);
                    };

                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
