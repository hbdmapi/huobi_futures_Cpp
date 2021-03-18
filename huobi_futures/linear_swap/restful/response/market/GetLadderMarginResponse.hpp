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
                struct GetLadderMarginResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    int64_t ts;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        string margin_mode;

                        string margin_account;

                        struct LeverInfo
                        {
                            int32_t lever_rate;

                            struct Ladder
                            {
                                float min_margin_balance;
                                JS::Nullable<float> max_margin_balance;
                                float min_margin_available;
                                JS::Nullable<float> max_margin_available;

                                JS_OBJ(min_margin_balance, max_margin_balance, min_margin_available, max_margin_available);
                            };
                            std::vector<Ladder> ladders;

                            JS_OBJ(lever_rate, ladders);
                        };
                        std::vector<LeverInfo> list;

                        JS_OBJ(symbol, contract_code, margin_mode, margin_account, list);
                    };
                    std::optional<std::vector<Data>> data;

                    JS_OBJ(status, err_code, err_msg, ts, data);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
