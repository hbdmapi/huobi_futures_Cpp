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
            namespace response_market
            {
                struct SubDepthResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        int64_t mrid;

                        int64_t id;

                        std::vector<std::vector<float>> asks;

                        std::vector<std::vector<float>> bids;

                        int64_t ts;

                        int64_t version;

                        string ch;

                        std::optional<string> event;

                        JS_OBJ(mrid, id, asks, bids, ts, version, ch, event);
                    };

                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
