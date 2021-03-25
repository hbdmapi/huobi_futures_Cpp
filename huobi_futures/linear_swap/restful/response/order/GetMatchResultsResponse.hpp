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
                struct GetMatchResultsResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Trade
                        {
                            string id;

                            int64_t match_id;

                            int64_t order_id;

                            string order_id_str;

                            string symbol;

                            string order_source;

                            string contract_code;

                            string direction;

                            string offset;

                            float trade_volume;

                            float trade_price;

                            float trade_turnover;

                            int64_t create_date;

                            float offset_profitloss;

                            float trade_fee;

                            string role;

                            string fee_asset;

                            string margin_mode;

                            string margin_account;

                            float real_profit;

                            JS_OBJ(id, match_id, order_id, order_id_str, symbol, order_source, contract_code,
                                   direction, offset, trade_volume, trade_price, trade_turnover, create_date, offset_profitloss,
                                   trade_fee, role, fee_asset, margin_mode, margin_account, real_profit);
                        };

                        std::vector<Trade> trades;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(trades, total_page, current_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures