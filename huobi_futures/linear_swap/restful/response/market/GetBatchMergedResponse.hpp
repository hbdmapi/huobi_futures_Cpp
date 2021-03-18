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
                struct GetBatchMergedResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    int64_t ts;

                    struct Tick
                    {
                        string contract_code;
                        
                        int64_t id;

                        string amount;

                        std::vector<float> ask;

                        std::vector<float> bid;

                        string open;

                        string close;

                        float count;

                        string high;

                        string low;

                        string vol;

                        string trade_turnover;

                        int64_t ts;

                        JS_OBJ(id, amount, ask, bid, open, close, count, high, low, vol, trade_turnover, ts);
                    };

                    std::optional<std::vector<Tick>> ticks;

                    JS_OBJ(status, err_code, err_msg, ts, ticks);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
