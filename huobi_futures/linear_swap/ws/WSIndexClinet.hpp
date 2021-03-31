#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/index/SubIndexResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::SubIndexResponse SubIndexResponse;

#include "huobi_futures/linear_swap/ws/response/index/ReqIndexResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::ReqIndexResponse ReqIndexResponse;

#include "huobi_futures/linear_swap/ws/response/index/SubStrKlineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::SubStrKlineResponse SubStrKlineResponse;

#include "huobi_futures/linear_swap/ws/response/index/ReqStrKlineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::ReqStrKlineResponse ReqStrKlineResponse;

#include "huobi_futures/linear_swap/ws/response/index/SubBasisResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::SubBasisResponse SubBasisResponse;

#include "huobi_futures/linear_swap/ws/response/index/ReqBasisResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_index::ReqBasisResponse ReqBasisResponse;

#include "huobi_futures/wsbase/WSSubData.hpp"
typedef huobi_futures::wsbase::WSSubData WSSubData;

#include "huobi_futures/wsbase/WSUnsubData.hpp"
typedef huobi_futures::wsbase::WSUnsubData WSUnsubData;

#include "huobi_futures/wsbase/WSReqData.hpp"
typedef huobi_futures::wsbase::WSReqData WSReqData;

#include "huobi_futures/utils/const_val.hpp"

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace ws
        {
            class WSIndexClient : public WebSocketOp
            {
            public:
                WSIndexClient(string host = utils::DEFAULT_HOST) : WebSocketOp("/ws_index", host)
                {
                    Connect();
                }

                ~WSIndexClient()
                {
                    Disconnect();
                }

                typedef std::function<void(const SubIndexResponse &data)> _OnSubIndex;
                void SubIndex(const string &contract_code, const string &period, _OnSubIndex callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".index." << period;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubIndexResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubIndexResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const ReqIndexResponse &data)> _OnReqIndex;
                void ReqIndex(const string &contract_code, const string &period, long from, long to, _OnReqIndex callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".index." << period;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqIndexResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqIndexResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubStrKlineResponse &data)> _OnSubStrKline;
                void SubPremiumIndex(const string &contract_code, const string &period, _OnSubStrKline callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".premium_index." << period;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const ReqStrKlineResponse &data)> _OnReqStrKline;
                void ReqPremiumIndex(const string &contract_code, const string &period, long from, long to, _OnReqStrKline callbackFun,
                                     const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".premium_index." << period;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void SubEstimatedRate(const string &contract_code, const string &period, _OnSubStrKline callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".estimated_rate." << period;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void ReqEstimatedRate(const string &contract_code, const string &period, long from, long to, _OnReqStrKline callbackFun,
                                      const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".estimated_rate." << period;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubBasisResponse &data)> _OnSubBasis;
                void SubBasis(const string &contract_code, const string &period, const string &basis_price_type,
                                     _OnSubBasis callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".basis." << period << "." << basis_price_type;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubBasisResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubBasisResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const ReqBasisResponse &data)> _OnReqBasis;
                void ReqBasis(const string &contract_code, const string &period, const string &basis_price_type, long from, long to,
                                     _OnReqBasis callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".basis." << period << "." << basis_price_type;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqBasisResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqBasisResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void SubMarkPrice(const string &contract_code, const string &period, _OnSubStrKline callbackFun, const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".mark_price." << period;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void ReqMarkPrice(const string &contract_code, const string &period, long from, long to, _OnReqStrKline callbackFun,
                                  const string &id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".mark_price." << period;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqStrKlineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqStrKlineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }
            };
        } // namespace ws
    }     // namespace linear_swap
} // namespace huobi_futures