#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/notify/SubAccountsResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubAccountsResponse SubAccountsResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubOrdersResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubOrdersResponse SubOrdersResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubPositionsResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubPositionsResponse SubPositionsResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubMatchOrdersResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubMatchOrdersResponse SubMatchOrdersResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubLiquidationOrdersResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubLiquidationOrdersResponse SubLiquidationOrdersResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubFundingRateResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubFundingRateResponse SubFundingRateResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubContractInfoResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubContractInfoResponse SubContractInfoResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubTriggerOrderResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubTriggerOrderResponse SubTriggerOrderResponse;

#include "huobi_futures/wsbase/WSOpData.hpp"
typedef huobi_futures::wsbase::WSOpData WSOpData;

#include "huobi_futures/wsbase/WSReqData.hpp"
typedef huobi_futures::wsbase::WSReqData WSReqData;

#include "huobi_futures/utils/const_val.hpp"

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace ws
        {
            class NotifyClient : public WebSocketOp
            {
            public:
                NotifyClient(const string &access_key, const string &secret_key, const string &host = utils::DEFAULT_HOST)
                    : WebSocketOp("/linear-swap-notification", host, access_key, secret_key)
                {
                    Connect();
                }

                ~NotifyClient()
                {
                    Disconnect();
                }

                // ----------------------------------------------------------------------------------------------------
                // sub orders start

                typedef std::function<void(const SubOrdersResponse &data)> _OnSubOrdersResponse;
                void IsolatedSubOrders(string contract_code, _OnSubOrdersResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubOrdersResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubOrdersResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                void CrossSubOrders(string contract_code, _OnSubOrdersResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubOrdersResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubOrdersResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void CrossUnsubOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub orders end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub accounts start

                typedef std::function<void(const SubAccountsResponse &data)> _OnSubAccountsResponse;
                void IsolatedSubAccounts(string contract_code, _OnSubAccountsResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "accounts." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubAccountsResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubAccountsResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubAccounts(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "accounts." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                void CrossSubAccounts(string margin_account, _OnSubAccountsResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "accounts_cross." << margin_account;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubAccountsResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubAccountsResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void CrossUnsubAccounts(string margin_account, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "accounts_cross." << margin_account;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub accounts end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub positions start

                typedef std::function<void(const SubPositionsResponse &data)> _OnSubPositionsResponse;
                void IsolatedSubPositions(string contract_code, _OnSubPositionsResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "positions." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubPositionsResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubPositionsResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubPositions(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "positions." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                void CrossSubPositions(string contract_code, _OnSubPositionsResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "positions_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubPositionsResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubPositionsResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void CrossUnsubPositions(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "positions_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub positions end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub matchOrders start

                typedef std::function<void(const SubMatchOrdersResponse &data)> _OnSubMatchOrdersResponse;
                void IsolatedSubMatchOrders(string contract_code, _OnSubMatchOrdersResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "matchOrders." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubMatchOrdersResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubMatchOrdersResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubMatchOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "matchOrders." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                void CrossSubMatchOrders(string contract_code, _OnSubMatchOrdersResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "matchOrders_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubMatchOrdersResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubMatchOrdersResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }
                // sub matchOrders end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub liquidation_orders start

                typedef std::function<void(const SubLiquidationOrdersResponse &data)> _OnSubLiquidationOrdersResponse;
                void SubLiquidationOrders(string contract_code, _OnSubLiquidationOrdersResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".liquidation_orders";
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubLiquidationOrdersResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubLiquidationOrdersResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void UnsubLiquidationOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".liquidation_orders";
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub liquidation_orders end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub funding_rate start

                typedef std::function<void(const SubFundingRateResponse &data)> _OnSubFundingRateResponse;
                void SubFundingRateOrders(string contract_code, _OnSubFundingRateResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".funding_rate";
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubFundingRateResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubFundingRateResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void UnsubFundingRateOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".funding_rate";
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub funding_rate end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub contract_info start

                typedef std::function<void(const SubContractInfoResponse &data)> _OnSubContractInfoResponse;
                void SubContractInfoOrders(string contract_code, _OnSubContractInfoResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".contract_info";
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubContractInfoResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubContractInfoResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void UnsubContractInfoOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << contract_code << ".contract_info";
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub contract_info end
                // ----------------------------------------------------------------------------------------------------

                // ----------------------------------------------------------------------------------------------------
                // sub trigger_order start

                typedef std::function<void(const SubTriggerOrderResponse &data)> _OnSubTriggerOrderResponse;
                void IsolatedSubTriggerOrder(string contract_code, _OnSubTriggerOrderResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "trigger_order." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubTriggerOrderResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubTriggerOrderResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubTriggerOrder(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "trigger_order." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                void CrossSubTriggerOrder(string contract_code, _OnSubTriggerOrderResponse callbackFun, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "trigger_order_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "sub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Sub(op_data.ToJson(), ch.str(), [&](const string &data) {
                        SubTriggerOrderResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubTriggerOrderResponse error";
                            LOG(ERROR) << data;
                            return;
                        }
                        callbackFun(obj);
                    });
                }

                void CrossUnsubTriggerOrder(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "trigger_order_cross." << contract_code;
                    WSOpData op_data;
                    op_data.op = "unsub";
                    op_data.topic = ch.str();
                    op_data.cid = cid;

                    Unsub(op_data.ToJson(), ch.str());
                }

                // sub trigger_order end
                // ----------------------------------------------------------------------------------------------------
            };
        } // namespace ws
    }     // namespace linear_swap
} // namespace huobi_futures