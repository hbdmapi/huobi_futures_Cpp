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
                struct ReqBasisResponse
                {
                    string rep;

                    string status;

                    string id;

                    int64_t wsid;

                    struct Data
                    {
                        int64_t id;

                        string contract_price;

                        string index_price;

                        string basis;

                        string basis_rate;

                        JS_OBJ(id, contract_price, index_price, basis, basis_rate);
                    };

                    std::vector<Data> data;

                    JS_OBJ(rep, status, id, wsid, data);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
