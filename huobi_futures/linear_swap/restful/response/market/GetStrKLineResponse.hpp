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
                struct GetStrKLineResponse
                {
                    std::optional<string> ch;

                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        int64_t id;

                        string vol;

                        string count;

                        string open;

                        string close;

                        string low;

                        string high;

                        string amount;

                        float trade_turnover;

                        JS_OBJ(id, vol, count, open, close, low, high, amount);
                    };
                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(ch, status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
