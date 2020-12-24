#pragma once

#include <string>
using std::string;

namespace huobi_futures
{
	namespace utils
	{
        const string DEFAULT_HOST = "api.btcgateway.pro";

        const string DEFAULT_ID = "api";

        const int WS_RECV_BUF_SIZE = 4096 * 100;
        const int WS_SEND_BUF_SIZE = 1024;
    } // namespace utils
} // namespace huobi_futures