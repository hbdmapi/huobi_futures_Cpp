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
            namespace response_transfer
            {
                struct TransferResponse
                {
                    string success;

                    JS::Nullable<int64_t> data;

                    int64_t code;

                    string message;

                    JS_OBJ(success, data, code, message);
                };
            } // namespace response_transfer
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
