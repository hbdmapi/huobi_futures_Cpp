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
                struct GetDepthResponse
                {
                    std::optional<string> ch;

                    string status;

                    std::optional<string> err_code;

                    std::optional<string> err_msg;

                    struct Tick
                    {
                        std::vector<std::vector<float>> asks;

                        std::vector<std::vector<float>> bids;

                        string ch;

                        int64_t id;

                        int64_t mrid;

                        int64_t ts;

                        int64_t version;

                        JS_OBJ(asks, bids, ch, id, mrid, ts, version);
                    };
                    JS::Nullable<Tick> tick;

                    int64_t ts;

                    JS_OBJ(ch, status, err_code, err_msg, tick, ts);
                };
            } // namespace response_market
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures
