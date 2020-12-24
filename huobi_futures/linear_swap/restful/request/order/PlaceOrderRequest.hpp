#pragma once

#include <string>
using std::string;

#include "huobi_futures/json_struct/json_struct.h"
#include <vector>
#include <optional>
#include <sstream>

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace restful
        {
            namespace request_order
            {
                struct PlaceOrderRequest
                {
                    string contract_code;

                    int64_t client_order_id;

                    float price;

                    int64_t volume;

                    string direction;

                    string offset;

                    int32_t lever_rate;

                    string order_price_type;

                    PlaceOrderRequest()
                    {
                        client_order_id = -1;
                    }

                    ///
                    // c++ var has not default value, client_order_id is a option param, so this to_json funciton is here.
                    ///
                    string to_json() const
                    {
                        stringstream str_buf;
                        str_buf << "{\"contract_code\":\"" << contract_code << "\",\"price\":" << price
                                << ",\"volume\":" << volume << ",\"direction\":\"" << direction << "\",\"offset\":\"" << offset
                                << "\",\"lever_rate\":" << lever_rate << ",\"order_price_type\":\"" << order_price_type
                                << "\"";
                        if (client_order_id != -1)
                        {
                            str_buf << "\"client_order_id\":" << client_order_id;
                        }
                        str_buf << "}";
                        return str_buf.str();
                    }
                };

            } // namespace request_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures