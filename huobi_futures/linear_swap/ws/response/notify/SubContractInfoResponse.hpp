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
        namespace ws
        {
            namespace response_notify
            {
                struct SubContractInfoResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    string event;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        float contract_size;

                        float price_tick;

                        string settlement_date;

                        string delivery_time;

                        string create_date;

                        int32_t contract_status;

                        string support_margin_mode;

                        JS_OBJ(contract_code, contract_size, price_tick, settlement_date,
                               delivery_time, create_date, contract_status, support_margin_mode);
                    };

                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, event, data);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
