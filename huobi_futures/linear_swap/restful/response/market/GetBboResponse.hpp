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
            namespace response_market
            {
                struct GetBboResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Tick
                    {
                        string contract_code;

                        int64_t mrid;

                        std::vector<float> ask;

                        std::vector<float> bid;

                        int64_t ts;

                        JS_OBJ(contract_code, mrid, ask, bid, ts);
                    };
                    JS::Nullable<std::vector<Tick>> ticks;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, ticks, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
