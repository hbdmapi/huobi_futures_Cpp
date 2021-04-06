#include "huobi_futures/linear_swap/ws/WebSocketOp.hpp"

#include "huobi_futures/linear_swap/ws/response/system/SubHeartbeatResponse.hpp"
typedef huobi_futures::linear_swap::ws::response_system::SubHeartbeatResponse SubHeartbeatResponse;

#include "huobi_futures/wsbase/WSOpData.hpp"
typedef huobi_futures::wsbase::WSOpData WSOpData;

#include "huobi_futures/utils/const_val.hpp"

namespace huobi_futures
{
    namespace linear_swap
    {
        namespace ws
        {
            class WSSystemClient : public WebSocketOp
            {
            public:
                WSSystemClient(string host = utils::DEFAULT_HOST) : WebSocketOp("/center-notification", host)
                {
                    Connect();
                }

                ~WSSystemClient()
                {
                    Disconnect();
                }

                typedef std::function<void(const SubHeartbeatResponse &data)> _OnSubHeartbeat;
                void SubHeartbeat(const string &service, _OnSubHeartbeat callbackFun, const string &cid = utils::DEFAULT_ID)
                {
                    stringstream ch;
                    ch << "public." << service << ".heartbeat";
                    WSOpData sub_data;
                    sub_data.op = "sub";
                    sub_data.topic = ch.str();

                    Sub(sub_data.ToJson(), ch.str(), [&](const string &data) {
                        SubHeartbeatResponse obj;
                        JS::ParseContext parseContext(data);
                        parseContext.allow_unnasigned_required_members = false;

                        if (parseContext.parseTo(obj) != JS::Error::NoError)
                        {
                            std::string errorStr = parseContext.makeErrorString();
                            LOG(ERROR) << "Error parsing struct SubHeartbeatResponse error";
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