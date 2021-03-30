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
                struct SubBboResponse
                {
                    string ch;

                    int64_t ts;

                    struct Tick
                    {
                        string ch;

                        int64_t mrid;

                        int64_t id;

                        std::vector<float> ask;

                        std::vector<float> bid;

                        int64_t version;

                        int64_t ts;

                        JS_OBJ(ch, mrid, id, ask, bid, version, ts);
                    };

                    Tick tick;

                    JS_OBJ(ch, ts, tick);
                };
            } // namespace response_market
        }     // namespace ws
    }         // namespace linear_swap
} // namespace huobi_futures
