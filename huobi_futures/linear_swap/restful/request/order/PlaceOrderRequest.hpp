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

                    float tp_trigger_price;

                    float tp_order_price;

                    string tp_order_price_type;

                    float sl_trigger_price;

                    float sl_order_price;

                    string sl_order_price_type;

                    PlaceOrderRequest()
                    {
                        price = 0;
                        client_order_id = 0;

                        tp_trigger_price = 0;
                        tp_order_price = 0;
                        tp_order_price_type = "";

                        sl_trigger_price = 0;
                        sl_order_price = 0;
                        sl_order_price_type = "";
                    }

                    ///
                    // c++ var has not default value, client_order_id is a option param, so this to_json funciton is here.
                    ///
                    string to_json() const
                    {
                        stringstream str_buf;
                        str_buf << "{\"contract_code\":\"" << contract_code << "\""
                                << ",\"volume\":" << volume << ",\"direction\":\"" << direction << "\",\"offset\":\"" << offset
                                << "\",\"lever_rate\":" << lever_rate << ",\"order_price_type\":\"" << order_price_type << "\"";
                        if (price != 0)
                        {
                            str_buf << ",\"price\":" << price;
                        }
                        if (client_order_id != 0)
                        {
                            str_buf << ",\"client_order_id\":" << client_order_id;
                        }
                        if (tp_trigger_price != 0)
                        {
                            str_buf << ",\"tp_trigger_price\":" << tp_trigger_price;
                        }
                        if (tp_order_price != 0)
                        {
                            str_buf << ",\"tp_order_price\":" << tp_order_price;
                        }
                        if (tp_order_price_type != "")
                        {
                            str_buf << ",\"tp_order_price_type\":\"" << tp_order_price_type << "\"";
                        }
                        if (sl_trigger_price != 0)
                        {
                            str_buf << ",\"sl_trigger_price\":" << sl_trigger_price;
                        }
                        if (sl_order_price != 0)
                        {
                            str_buf << ",\"sl_order_price\":" << sl_order_price;
                        }
                        if (sl_order_price_type != "")
                        {
                            str_buf << ",\"sl_order_price_type\":\"" << sl_order_price_type << "\"";
                        }
                        str_buf << "}";
                        return str_buf.str();
                    }
                };

            } // namespace request_order
        }     // namespace restful
    }         // namespace linear_swap
} // namespace huobi_futures