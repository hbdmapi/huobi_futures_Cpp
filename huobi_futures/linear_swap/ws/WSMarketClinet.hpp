#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/market/SubKLineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubKLineResponse SubKLineResponse;

#include "huobi_futures/linear_swap/ws/response/market/ReqKLineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::ReqKLineResponse ReqKLineResponse;

#include "huobi_futures/linear_swap/ws/response/market/SubDepthResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubDepthResponse SubDepthResponse;

#include "huobi_futures/linear_swap/ws/response/market/SubBboResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubBboResponse SubBboResponse;

#include "huobi_futures/linear_swap/ws/response/market/ReqTradeDetailResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::ReqTradeDetailResponse ReqTradeDetailResponse;

#include "huobi_futures/linear_swap/ws/response/market/SubTradeDetailResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubTradeDetailResponse SubTradeDetailResponse;

#include "huobi_futures/linear_swap/ws/response/market/SubMarketDetailResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubMarketDetailResponse SubMarketDetailResponse;

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
            class WSMarketClient : public WebSocketOp
            {
            public:
                WSMarketClient(string host = utils::DEFAULT_HOST) : WebSocketOp("/linear-swap-ws", host)
                {
                    Connect();
                }

                ~WSMarketClient()
                {
                    Disconnect();
                }

                typedef std::function<void(const SubKLineResponse &data)> _OnSubKLine;
                void SubKLine(string contract_code, string period, _OnSubKLine callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".kline." << period;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubKLineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubKLineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }
                
                typedef std::function<void(const ReqKLineResponse &data)> _OnReqKLine;
                void ReqKLine(string contract_code, string period, long from, long to, _OnReqKLine callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".kline." << period;
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.from = from;
                    req_data.to = to;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqKLineResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqKLineResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubDepthResponse &data)> _OnSubDepth;
                void SubDepth(string contract_code, string type, _OnSubDepth callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".depth." << type;
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubDepthResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubDepthResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void SubDepthIncremental(string contract_code, string size, _OnSubDepth callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".depth." << size << ".high_freq";
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;
                    sub_data.data_type = "incremental";

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubDepthResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubDepthResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubMarketDetailResponse &data)> _OnSubMarketDetail;
                void SubMarketDetail(string contract_code, _OnSubMarketDetail callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".detail";
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubMarketDetailResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubMarketDetailResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubBboResponse &data)> _OnSubBbo;
                void SubBbo(string contract_code, _OnSubBbo callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".bbo";
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubBboResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubBboResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const ReqTradeDetailResponse &data)> _OnReqTradeDetail;
                void ReqTradeDetail(string contract_code, _OnReqTradeDetail callbackFun, int size = 0, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".trade.detail";
                    WSReqData req_data;
                    req_data.req = ch.str();
                    req_data.id = id;
                    req_data.size = size;

                    Req(req_data.ToJson(), ch.str(), [&](const string &data) {
                        ReqTradeDetailResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct ReqTradeDetailResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                typedef std::function<void(const SubTradeDetailResponse &data)> _OnSubTradeDetail;
                void SubTradeDetail(string contract_code, _OnSubTradeDetail callbackFun, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".trade.detail";
                    WSSubData sub_data;
                    sub_data.sub = ch.str();
                    sub_data.id = id;

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubTradeDetailResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubTradeDetailResponse error";
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