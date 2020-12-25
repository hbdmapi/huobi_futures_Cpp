#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/notify/SubAccountsResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubAccountsResponse SubAccountsResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubOrdersResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubOrdersResponse SubOrdersResponse;

#include "huobi_futures/linear_swap/ws/response/notify/SubPositionsResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_notify::SubPositionsResponse SubPositionsResponse;

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
                        }
                        callbackFun(obj);
                    });
                }

                void IsolatedUnsubOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders_cross." << contract_code;
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
                        }
                        callbackFun(obj);
                    });
                }

                void CrossUnsubOrders(string contract_code, string cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "orders." << contract_code;
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
            };
        } // namespace ws
    }     // namespace linear_swap
} // namespace huobi_futures