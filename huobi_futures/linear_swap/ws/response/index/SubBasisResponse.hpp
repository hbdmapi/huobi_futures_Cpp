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
            namespace response_index
            {
                struct SubBasisResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        int64_t id;

                        string contract_price;

                        string index_price;

                        string basis;

                        string basis_rate;

                        JS_OBJ(id, contract_price, index_price, basis, basis_rate);
                    };
                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures