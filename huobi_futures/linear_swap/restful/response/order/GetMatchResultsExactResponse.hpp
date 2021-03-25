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
                struct GetMatchResultsExactResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Trade
                        {
                            string id;

                            int64_t query_id;

                            int64_t match_id;

                            int64_t order_id;

                            string order_id_str;

                            string symbol;

                            string contract_code;

                            string margin_mode;

                            string margin_account;

                            string direction;

                            string offset;

                            float trade_volume;

                            float trade_price;

                            float trade_turnover;

                            int64_t create_date;

                            float offset_profitloss;

                            float real_profit;

                            float trade_fee;

                            string order_source;

                            string role;

                            string fee_asset;

                            JS_OBJ(id, query_id, match_id, order_id, order_id_str, symbol, contract_code, margin_mode,
                                   margin_account, direction, offset, trade_volume, trade_price, trade_turnover, create_date,
                                   offset_profitloss, real_profit, trade_fee, order_source, role, fee_asset);
                        };

                        std::vector<Trade> trades;

                        int32_t remain_size;

                        JS::Nullable<int64_t> next_id;

                        JS_OBJ(trades, remain_size, next_id);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures