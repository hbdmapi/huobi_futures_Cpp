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
                struct GetSettlementRecordsResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {
                        struct SettlementRecord
                        {
                            string symbol;

                            string contract_code;

                            int64_t settlement_time;

                            float clawback_ratio;

                            float settlement_price;

                            string settlement_type;

                            JS_OBJ(symbol, contract_code, settlement_time, clawback_ratio, settlement_price, settlement_type);
                        };
                        std::vector<SettlementRecord> settlement_record;

                        int32_t total_page;

                        int32_t current_page;

                        int32_t total_size;

                        JS_OBJ(settlement_record, total_page, current_page, total_size);
                    };
                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
