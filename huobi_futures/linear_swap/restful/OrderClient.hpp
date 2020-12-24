#pragma once

#include <future>
#include <sstream>

#include "huobi_futures/url_base/PrivateUrlBuilder.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"
#include "huobi_futures/utils/const_val.hpp"

#include "huobi_futures/linear_swap/restful/response/order/CancelOrderResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_order::CancelOrderResponse CancelOrderResponse;

#include "huobi_futures/linear_swap/restful/response/order/GetOrderInfoResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_order::GetOrderInfoResponse GetOrderInfoResponse;

#include "huobi_futures/linear_swap/restful/request/order/PlaceOrderRequest.hpp"
typedef huobi_futures::linear_swap::restful::request_order::PlaceOrderRequest PlaceOrderRequest;

#include "huobi_futures/linear_swap/restful/response/order/PlaceOrderResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_order::PlaceOrderResponse PlaceOrderResponse;

#include "huobi_futures/linear_swap/restful/response/order/SwitchLeverRateResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_order::SwitchLeverRateResponse SwitchLeverRateResponse;

#include "huobi_futures/linear_swap/restful/response/order/GetOpenOrderResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_order::GetOpenOrderResponse GetOpenOrderResponse;

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace restful
        {
            class OrderClient
            {

            public:
                OrderClient(const string &access_key, const string &secret_key, const string &host = utils::DEFAULT_HOST)
                {
                    pb = std::make_shared<url_base::PrivateUrlBuilder>(access_key, secret_key, host);
                }

                std::shared_ptr<CancelOrderResponse> IsolatedCancelOrder(const string &contract_code, const string &order_id = "",
                                                                         const string &client_order_id = "")
                {
                    // path
                    stringstream path;
                    if (order_id.empty() && client_order_id.empty())
                    {
                        path << "/linear-swap-api/v1/swap_cancelall";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_cancel";
                    }

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\"";
                    if (order_id != "")
                    {
                        content << ",\"order_id\":\"" << order_id << "\"";
                    }
                    if (client_order_id != "")
                    {
                        content << ",\"client_order_id\":\"" << client_order_id << "\"";
                    }

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<CancelOrderResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<CancelOrderResponse> CrossCancelOrder(const string &contract_code, const string &order_id = "",
                                                                      const string &client_order_id = "")
                {
                    // path
                    stringstream path;
                    if (order_id.empty() && client_order_id.empty())
                    {
                        path << "/linear-swap-api/v1/swap_cross_cancelall";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_cross_cancel";
                    }

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\"";
                    if (order_id != "")
                    {
                        content << ",\"order_id\":\"" << order_id << "\"";
                    }
                    if (client_order_id != "")
                    {
                        content << ",\"client_order_id\":\"" << client_order_id << "\"";
                    }

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<CancelOrderResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetOrderInfoResponse> IsolatedGetOrderInfo(const string &contract_code, const string &order_id = "",
                                                                           const string &client_order_id = "")
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_order_info";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\"";
                    if (order_id != "")
                    {
                        content << ",\"order_id\":\"" << order_id << "\"";
                    }
                    if (client_order_id != "")
                    {
                        content << ",\"client_order_id\":\"" << client_order_id << "\"";
                    }

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<GetOrderInfoResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetOrderInfoResponse> CrossGetOrderInfo(const string &contract_code, const string &order_id = "",
                                                                        const string &client_order_id = "")
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_cross_order_info";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\"";
                    if (order_id != "")
                    {
                        content << ",\"order_id\":\"" << order_id << "\"";
                    }
                    if (client_order_id != "")
                    {
                        content << ",\"client_order_id\":\"" << client_order_id << "\"";
                    }

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<GetOrderInfoResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<PlaceOrderResponse> IsolatedPlaceOrder(const PlaceOrderRequest &request)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_order";

                    // option
                    string data = request.to_json();

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<PlaceOrderResponse>(url, data);
                    return result;
                }

                std::shared_ptr<PlaceOrderResponse> CrossPlaceOrder(const PlaceOrderRequest &request)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_cross_order";

                    // option
                    string data = request.to_json();

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<PlaceOrderResponse>(url, data);
                    return result;
                }

                std::shared_ptr<SwitchLeverRateResponse> IsolatedSwitchLeverRate(const string &contract_code, int lever_rate)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_switch_lever_rate";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\""
                            << ",\"lever_rate\":" << lever_rate;

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<SwitchLeverRateResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<SwitchLeverRateResponse> CrossSwitchLeverRate(const string &contract_code, int lever_rate)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_cross_switch_lever_rate";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\""
                            << ",\"lever_rate\":" << lever_rate;

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<SwitchLeverRateResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetOpenOrderResponse> IsolatedGetOpenOrder(const string &contract_code, int page_index = 1,
                                                                           int page_size = 20)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_openorders";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\""
                            << ",\"page_index\":" << page_index
                            << ",\"page_size\":" << page_size;

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<GetOpenOrderResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetOpenOrderResponse> CrossGetOpenOrder(const string &contract_code, int page_index = 1,
                                                                        int page_size = 20)
                {
                    // path
                    stringstream path;
                    path << "/linear-swap-api/v1/swap_cross_openorders";

                    // option
                    stringstream content;
                    content << ",\"contract_code\":\"" << contract_code << "\""
                            << ",\"page_index\":" << page_index
                            << ",\"page_size\":" << page_size;

                    // data
                    stringstream data;
                    if (!content.str().empty())
                    {
                        data << "{" << content.str().substr(1) << "}";
                    }

                    // url
                    string url = pb->Build("POST", path.str());

                    // post
                    auto result = url_base::HttpRequest::Instance().Post<GetOpenOrderResponse>(url, data.str());
                    return result;
                }

            private:
                std::shared_ptr<url_base::PrivateUrlBuilder> pb;
            };
        } // namespace restful
    }     // namespace linear_swap
} // namespace huobi_futures
