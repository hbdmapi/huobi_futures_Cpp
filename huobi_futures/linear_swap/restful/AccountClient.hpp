#pragma once

#include <future>
#include <sstream>

#include "huobi_futures/url_base/PrivateUrlBuilder.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"
#include "huobi_futures/utils/const_val.hpp"

#include "huobi_futures/linear_swap/restful/response/account/GetAccountInfoResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_account::GetAccountInfoResponse GetAccountInfoResponse;

#include "huobi_futures/linear_swap/restful/response/account/GetAccountPositionResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_account::GetAccountPositionResponse GetAccountPositionResponse;

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace restful
        {
            class AccountClient
            {

            public:
                AccountClient(const string &access_key, const string &secret_key, const string &host = utils::DEFAULT_HOST)
                {
                    pb = std::make_shared<url_base::PrivateUrlBuilder>(access_key, secret_key, host);
                }

                std::shared_ptr<GetAccountInfoResponse> IsolatedGetAccountInfo(const string &contract_code = "", int sub_uid = -1)
                {
                    // path
                    stringstream path;
                    if (sub_uid == -1)
                    {
                        path << "/linear-swap-api/v1/swap_account_info";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_sub_account_info";
                    }

                    // option
                    stringstream content;
                    if (contract_code != "")
                    {
                        content << ",\"contract_code\":\"" << contract_code << "\"";
                    }
                    if (sub_uid != -1)
                    {
                        content << ",\"sub_uid\":" << sub_uid;
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
                    url_base::HttpRequest hr;
                    auto result = hr.Post<GetAccountInfoResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetAccountInfoResponse> CrossGetAccountInfo(const string &margin_account = "USDT", int sub_uid = -1)
                {
                    // path
                    stringstream path;
                    if (sub_uid == -1)
                    {
                        path << "/linear-swap-api/v1/swap_cross_account_info";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_sub_account_info";
                    }

                    // option
                    stringstream content;
                    if (margin_account != "")
                    {
                        content << ",\"margin_account\":\"" << margin_account << "\"";
                    }
                    if (sub_uid != -1)
                    {
                        content << ",\"sub_uid\":" << sub_uid;
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
                    url_base::HttpRequest hr;
                    auto result = hr.Post<GetAccountInfoResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetAccountPositionResponse> IsolatedGetAccountPosition(const string &contract_code = "", int sub_uid = -1)
                {
                    // path
                    stringstream path;
                    if (sub_uid == -1)
                    {
                        path << "/linear-swap-api/v1/swap_position_info";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_sub_position_info";
                    }

                    // option
                    stringstream content;
                    if (contract_code != "")
                    {
                        content << ",\"contract_code\":\"" << contract_code << "\"";
                    }
                    if (sub_uid != -1)
                    {
                        content << ",\"sub_uid\":" << sub_uid;
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
                    url_base::HttpRequest hr;
                    auto result = hr.Post<GetAccountPositionResponse>(url, data.str());
                    return result;
                }

                std::shared_ptr<GetAccountPositionResponse> CrossGetAccountPosition(const string &contract_code = "", int sub_uid = -1)
                {
                    // path
                    stringstream path;
                    if (sub_uid == -1)
                    {
                        path << "/linear-swap-api/v1/swap_cross_position_info";
                    }
                    else
                    {
                        path << "/linear-swap-api/v1/swap_cross_sub_position_info";
                    }

                    // option
                    stringstream content;
                    if (contract_code != "")
                    {
                        content << ",\"contract_code\":\"" << contract_code << "\"";
                    }
                    if (sub_uid != -1)
                    {
                        content << ",\"sub_uid\":" << sub_uid;
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
                    url_base::HttpRequest hr;
                    auto result = hr.Post<GetAccountPositionResponse>(url, data.str());
                    return result;
                }

            private:
                std::shared_ptr<url_base::PrivateUrlBuilder> pb;
            };
        } // namespace restful
    }     // namespace linear_swap
} // namespace huobi_futures
