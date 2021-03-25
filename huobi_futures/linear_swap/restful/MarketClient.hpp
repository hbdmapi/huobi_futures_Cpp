#pragma once

#include <future>
#include <sstream>
using std::stringstream;

#include "huobi_futures/url_base/PublicUrlBuilder.hpp"
#include "huobi_futures/url_base/HttpRequest.hpp"
#include "huobi_futures/utils/const_val.hpp"

#include "huobi_futures/linear_swap/restful/response/market/GetContractInfoResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetContractInfoResponse GetContractInfoResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetIndexResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetIndexResponse GetIndexResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetPriceLimitResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetPriceLimitResponse GetPriceLimitResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetOpenInterestResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetOpenInterestResponse GetOpenInterestResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetDepthResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetDepthResponse GetDepthResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetKLineResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetKLineResponse GetKLineResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetMergedResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetMergedResponse GetMergedResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetBatchMergedResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetBatchMergedResponse GetBatchMergedResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetTradeResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetTradeResponse GetTradeResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetHisTradeResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetHisTradeResponse GetHisTradeResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetRiskInfoResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetRiskInfoResponse GetRiskInfoResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetInsurancefundResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetInsurancefundResponse GetInsurancefundResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetAdjustfactorResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetAdjustfactorResponse GetAdjustfactorResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetEstimatedSettlementPriceResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetEstimatedSettlementPriceResponse GetEstimatedSettlementPriceResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetHisOpenInterestResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetHisOpenInterestResponse GetHisOpenInterestResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetLadderMarginResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetLadderMarginResponse GetLadderMarginResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetEliteRatioResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetEliteRatioResponse GetEliteRatioResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetApiStatusResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetApiStatusResponse GetApiStatusResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetTransferStatusResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetTransferStatusResponse GetTransferStatusResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetTradeStatusResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetTradeStatusResponse GetTradeStatusResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetFundingRateResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetFundingRateResponse GetFundingRateResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetHisFundingRateResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetHisFundingRateResponse GetHisFundingRateResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetLiquidationOrdersResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetLiquidationOrdersResponse GetLiquidationOrdersResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetSettlementRecordsResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetSettlementRecordsResponse GetSettlementRecordsResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetStrKLineResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetStrKLineResponse GetStrKLineResponse;

#include "huobi_futures/linear_swap/restful/response/market/GetBasisResponse.hpp"
typedef huobi_futures::linear_swap::restful::response_market::GetBasisResponse GetBasisResponse;

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

                std::shared_ptr<GetIndexResponse> GetIndex(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_index";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetIndexResponse>(url);
                    return result;
                }

                std::shared_ptr<GetPriceLimitResponse> GetPriceLimit(const string &contract_code)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_price_limit?contract_code=" << contract_code;

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetPriceLimitResponse>(url);
                    return result;
                }

                std::shared_ptr<GetOpenInterestResponse> GetOpenInterest(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_open_interest";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetOpenInterestResponse>(url);
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

                std::shared_ptr<GetKLineResponse> GetKLine(const string &contract_code, const string &period, int size = 150, long from = 0, long to = 0)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/history/kline";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period;
                    if (size != 0)
                    {
                        option << "&size=" << size;
                    }
                    if (from != 0 && to != 0)
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

                std::shared_ptr<GetKLineResponse> GetMarkPriceKLine(const string &contract_code, const string &period, int size)
                {
                    // location
                    stringstream location;
                    location << "/index/market/history/linear_swap_mark_price_kline";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period << "&size=" << size;

                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetKLineResponse>(url);
                    return result;
                }

                std::shared_ptr<GetMergedResponse> GetMerged(const string &contract_code)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/detail/merged";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code;

                    if (!contract_code.empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetMergedResponse>(url);
                    return result;
                }

                std::shared_ptr<GetBatchMergedResponse> GetBatchMerged(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/detail/batch_merged";

                    // option
                    stringstream option;
                    if (!contract_code.empty())
                    {
                        option << "contract_code=" << contract_code;
                    }

                    if (!contract_code.empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetBatchMergedResponse>(url);
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

                    if (!contract_code.empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetTradeResponse>(url);
                    return result;
                }

                std::shared_ptr<GetHisTradeResponse> GetHisTrade(const string &contract_code, int size = 1)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-ex/market/history/trade";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&size=" << size;

                    if (!contract_code.empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetHisTradeResponse>(url);
                    return result;
                }

                std::shared_ptr<GetRiskInfoResponse> GetRiskInfo(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_risk_info";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetRiskInfoResponse>(url);
                    return result;
                }

                std::shared_ptr<GetInsurancefundResponse> GetInsurancefund(const string &contract_code, int page_index = 1, int page_size = 100)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_insurance_fund";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&page_index=" << page_index << "&page_size=" << page_size;

                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetInsurancefundResponse>(url);
                    return result;
                }

                std::shared_ptr<GetAdjustfactorResponse> IsolatedGetAdjustfactor(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_adjustfactor";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetAdjustfactorResponse>(url);
                    return result;
                }

                std::shared_ptr<GetAdjustfactorResponse> CrossGetAdjustfactor(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_cross_adjustfactor";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetAdjustfactorResponse>(url);
                    return result;
                }

                std::shared_ptr<GetEstimatedSettlementPriceResponse> GetEstimatedSettlementPrice(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_estimated_settlement_price";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetEstimatedSettlementPriceResponse>(url);
                    return result;
                }

                std::shared_ptr<GetHisOpenInterestResponse> GetHisOpenInterest(const string &contract_code, const string &period, int amount_type, int size = 48)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_his_open_interest";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period << "&amount_type=" << amount_type << "&size=" << size;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetHisOpenInterestResponse>(url);
                    return result;
                }

                std::shared_ptr<GetLadderMarginResponse> IsolatedGetLadderMargin(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_ladder_margin";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetLadderMarginResponse>(url);
                    return result;
                }

                std::shared_ptr<GetLadderMarginResponse> CrossGetLadderMargin(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_cross_ladder_margin";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetLadderMarginResponse>(url);
                    return result;
                }

                std::shared_ptr<GetEliteRatioResponse> GetEliteAccountRatio(const string &contract_code, const string &period)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_elite_account_ratio";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetEliteRatioResponse>(url);
                    return result;
                }

                std::shared_ptr<GetEliteRatioResponse> GetElitePositionRatio(const string &contract_code, const string &period)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_elite_position_ratio";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetEliteRatioResponse>(url);
                    return result;
                }

                std::shared_ptr<GetApiStatusResponse> IsolatedGetApiStatus(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_api_state";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetApiStatusResponse>(url);
                    return result;
                }

                std::shared_ptr<GetTransferStatusResponse> CrossGetTransferStatus(const string &margin_account = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_cross_transfer_state";

                    // option
                    stringstream option;
                    if (margin_account != "")
                    {
                        option << "margin_account=" << margin_account;
                    }
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetTransferStatusResponse>(url);
                    return result;
                }

                std::shared_ptr<GetTradeStatusResponse> CrossGetTradeStatus(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_cross_trade_state";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetTradeStatusResponse>(url);
                    return result;
                }

                std::shared_ptr<GetFundingRateResponse> GetFundingRate(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_funding_rate";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetFundingRateResponse>(url);
                    return result;
                }

                std::shared_ptr<GetHisFundingRateResponse> GetHisFundingRate(const string &contract_code = "")
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_historical_funding_rate";

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

                    auto result = url_base::HttpRequest::Instance().Get<GetHisFundingRateResponse>(url);
                    return result;
                }

                std::shared_ptr<GetLiquidationOrdersResponse> GetLiquidationOrders(const string &contract_code, int trade_type,
                                                                                   int create_date, int page_index = 1, int page_size = 20)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_liquidation_orders";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&trade_type=" << trade_type << "&create_date=" << create_date
                           << "&page_index=" << page_index << "&page_size=" << page_size;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetLiquidationOrdersResponse>(url);
                    return result;
                }

                std::shared_ptr<GetSettlementRecordsResponse> GetSettlementRecords(const string &contract_code, long start_time = 0,
                                                                                   long end_time = 0, int page_index = 1, int page_size = 20)
                {
                    // location
                    stringstream location;
                    location << "/linear-swap-api/v1/swap_settlement_records";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&page_index=" << page_index << "&page_size=" << page_size;
                    if (start_time != 0)
                    {
                        option << "&start_time=" << start_time;
                    }
                    if (end_time != 0)
                    {
                        option << "&end_time=" << end_time;
                    }
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetSettlementRecordsResponse>(url);
                    return result;
                }

                std::shared_ptr<GetStrKLineResponse> GetPremiumIndexKlineResponse(const string &contract_code, const string &period, int size)
                {
                    // location
                    stringstream location;
                    location << "/index/market/history/linear_swap_premium_index_kline";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period << "&size=" << size;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetStrKLineResponse>(url);
                    return result;
                }

                std::shared_ptr<GetStrKLineResponse> GetEstimatedRateKlineResponse(const string &contract_code, const string &period, int size)
                {
                    // location
                    stringstream location;
                    location << "/index/market/history/linear_swap_estimated_rate_kline";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period << "&size=" << size;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetStrKLineResponse>(url);
                    return result;
                }

                std::shared_ptr<GetBasisResponse> GetBasis(const string &contract_code, const string &period,
                                                           const string &basis_price_type = "open", int size = 150)
                {
                    // location
                    stringstream location;
                    location << "/index/market/history/linear_swap_basis";

                    // option
                    stringstream option;
                    option << "contract_code=" << contract_code << "&period=" << period << "&basis_price_type=" << basis_price_type << "&size=" << size;
                    if (!option.str().empty())
                    {
                        location << "?" << option.str();
                    }

                    string url = pb->Build(location.str());

                    auto result = url_base::HttpRequest::Instance().Get<GetBasisResponse>(url);
                    return result;
                }

            private:
                std::shared_ptr<url_base::PublicUrlBuilder> pb;
            };
        } // namespace restful
    }     // namespace linear_swap
} // namespace huobi_futures
