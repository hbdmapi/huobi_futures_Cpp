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
                struct GetContractInfoResponse
                {
                    string status;

                    std::optional<int32_t> err_code;
                    
                    std::optional<string> err_msg;

                    struct Data
                    {
                        string symbol;

                        string contract_code;

                        float contract_size;

                        float price_tick;

                        string settlement_date;

                        string create_date;

                        int32_t contract_status;

                        JS_OBJ(symbol, contract_code, contract_size, price_tick, settlement_date, create_date, contract_status);
                    };

                    std::optional<std::vector<Data>> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures