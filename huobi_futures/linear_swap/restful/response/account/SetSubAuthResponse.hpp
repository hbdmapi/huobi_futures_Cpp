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
                struct SetSubAuthResponse
                {
                    string status;

                    std::optional<int32_t> err_code;

                    std::optional<string> err_msg;

                    struct Data
                    {

                        struct Error
                        {
                            string sub_uid;

                            int32_t err_code;

                            string err_msg;

                            JS_OBJ(sub_uid, err_code, err_msg);
                        };
                        std::vector<Error> errors;

                        string successes;

                        JS_OBJ(errors, successes);
                    };

                    std::optional<Data> data;

                    int64_t ts;

                    JS_OBJ(status, err_code, err_msg, data, ts);
                };
            } // namespace response_account
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
