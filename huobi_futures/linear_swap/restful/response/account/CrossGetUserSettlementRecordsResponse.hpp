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
                struct CrossGetUserSettlementRecordsResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct Settlement
                        {
                            string margin_mode;

                            string margin_account;

                            float margin_balance_init;

                            float margin_balance;

                            float settlement_profit_real;

                            int64_t settlement_time;

                            float clawback;

                            float funding_fee;

                            float offset_profitloss;

                            float fee;

                            string fee_asset;

                            struct Contract
                            {

                                string symbol;

                                string contract_code;

                                float offset_profitloss;

                                float fee;

                                string fee_asset;

                                struct Position
                                {
                                    string symbol;

                                    string contract_code;

                                    string direction;

                                    float volume;

                                    float cost_open;

                                    float cost_hold_pre;

                                    float cost_hold;

                                    float settlement_profit_unreal;

                                    float settlement_price;

                                    string settlement_type;

                                    JS_OBJ(symbol, contract_code, direction, volume, cost_open, cost_hold_pre, cost_hold,
                                           settlement_profit_unreal, settlement_price, settlement_type);
                                };
                                std::vector<Position> positions;

                                JS_OBJ(symbol, contract_code, offset_profitloss, fee, fee_asset, positions);
                            };

                            std::vector<Contract> contract_detail;

                            JS_OBJ(margin_mode, margin_account, margin_balance_init, margin_balance, settlement_profit_real,
                                   settlement_time, clawback, funding_fee, offset_profitloss, fee, fee_asset, contract_detail);
                        };

                        std::vector<Settlement> settlement_records;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(settlement_records, total_page, current_page, total_size);
                    };

                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
