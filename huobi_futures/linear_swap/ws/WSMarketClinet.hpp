#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/market/SubKLineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubKLineResponse SubKLineResponse;

#include "huobi_futures/linear_swap/ws/response/market/ReqKLineResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::ReqKLineResponse ReqKLineResponse;

#include "huobi_futures/linear_swap/ws/response/market/SubDepthResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_market::SubDepthResponse SubDepthResponse;

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

                typedef std::function<void(const SubKLineResponse &data)> _OnSubKLineResponse;
                void SubKLine(string contract_code, string period, _OnSubKLineResponse callbackFun, string id = utils::DEFAULT_ID)
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

                void UnsubKLine(string contract_code, string period, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".kline." << period;
                    WSUnsubData unsub_data;
                    unsub_data.unsub = ch.str();
                    unsub_data.id = id;

                    Unsub(unsub_data.ToJson(), ch.str());
                }

                typedef std::function<void(const ReqKLineResponse &data)> _OnReqKLineResponse;
                void ReqKLine(string contract_code, string period, long from, long to, _OnReqKLineResponse callbackFun, string id = utils::DEFAULT_ID)
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

                typedef std::function<void(const SubDepthResponse &data)> _OnSubDepthResponse;
                void SubDepth(string contract_code, string type, _OnSubDepthResponse callbackFun, string id = utils::DEFAULT_ID)
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

                void UnSubDepth(string contract_code, string type, string id = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "market." << contract_code << ".depth." << type;
                    WSUnsubData unsub_data;
                    unsub_data.unsub = ch.str();
                    unsub_data.id = id;

                    Unsub(unsub_data.ToJson(), ch.str());
                }
            };
        } // namespace ws
    }     // namespace linear_swap
} // namespace huobi_futures