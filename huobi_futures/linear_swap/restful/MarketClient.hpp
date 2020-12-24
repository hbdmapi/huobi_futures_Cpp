#pragma once

#include <future>
#include <sstream>
using std::stringstream;

#include "huobi_futures/url_base/PublicUrlBuilder.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"
#include "huobi_futures/utils/const_val.hpp"

#include "huobi_futures/linear_swap/restful/response/market/GetContractInfoResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetContractInfoResponse GetContractInfoResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetDepthResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetDepthResponse GetDepthResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetKLineResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetKLineResponse GetKLineResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetTradeResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetTradeResponse GetTradeResponse;

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace restful
        {
            class MarketClient
            {

            public:
                MarketClient(const string &host = utils::DEFAULT_HOST)
                {
                    pb = std::make_shared<url_base::PublicUrlBuilder>(host);
                }

                std::shared_ptr<GetContractInfoResponse> GetContractInfo(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_contract_info";

                    // option
                    stringstream option;
                    if (contract_code != "")
                    {
                        option << "contract_code=" << contract_code;
                    }
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetContractInfoResponse>(url);
                    return result;
                }

                std::shared_ptr<GetDepthResponse> GetDepth(const string &contract_code, const string &type)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/depth";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&type=" << type;

                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetDepthResponse>(url);
                    return result;
                }

                std::shared_ptr<GetKLineResponse> GetKLine(const string &contract_code, const string &period, int size = 150, long from = -1, long to = -1)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/history/kline";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period;
                    if (size != -1)
                    {
                        option << "&size=" << size;
                    }
                    if (from != -1 && to != -1)
                    {
                        option << "&from=" << size << "&to=" << to;
                    }

                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetKLineResponse>(url);
                    return result;
                }

                std::shared_ptr<GetTradeResponse> GetTrade(const string &contract_code)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/trade";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code;

                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetTradeResponse>(url);
                    return result;
                }

            private:
                std::shared_ptr<url_base::PublicUrlBuilder> pb;
            };
        } // namespace restful
    }     // namespace linear_swap
} // namespace huobi_futures
