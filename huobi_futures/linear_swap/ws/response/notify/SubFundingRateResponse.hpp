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
                struct SubFundingRateResponse
                {
                    string op;

                    string topic;

                    int64_t ts;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string fee_asset;

                        string funding_time;

                        string funding_rate;

                        string estimated_rate;

                        string settlement_time;

                        JS_OBJ(symbol, contract_code, fee_asset, funding_time, funding_rate, estimated_rate, settlement_time);
                    };

                    std::vector<Data> data;

                    JS_OBJ(op, topic, ts, data);
                };
            } // namespace response_notify
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
