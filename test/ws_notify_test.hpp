#include <gtest/gtest.h>

#include "config.hpp"
#include <thread>
#include <chrono>

#include "huobi_futures/linear_swap/ws/WSNotifyClinet.hpp"
typedef huobi_futures::linear_swap::ws::NotifyClient NotifyClient;

// TEST(NotifyClient, SubOrders)
// {
//     extern map<string, string> config;
//     init_config();

//     NotifyClient ws(config["AccessKey"], config["SecretKey"]);
//     ws.IsolatedSubOrders("XRP-USDT", [](const SubOrdersResponse &data) {
//         LOG(INFO) << data.margin_asset << "/" << data.margin_mode;
//     });
//     ws.CrossSubOrders("XRP-USDT", [](const SubOrdersResponse &data) {
//         LOG(INFO) << data.margin_asset << "/" << data.margin_mode;
//     });
//     ws.RunForever();
// }

TEST(NotifyClient, SubAccounts)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubAccounts("BTC-USDT", [](const SubAccountsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code.value() << ":" << item.margin_mode << "/" << item.margin_balance;
        }
    });
    ws.CrossSubAccounts("USDT", [](const SubAccountsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.margin_mode << ":" << item.margin_asset << "/" << item.margin_balance;
        }
    });
    ws.RunForever();
}

// TEST(NotifyClient, SubPositions)
// {
//     extern map<string, string> config;
//     init_config();

//     NotifyClient ws(config["AccessKey"], config["SecretKey"]);
//     ws.IsolatedSubPositions("XRP-USDT", [](const SubPositionsResponse &data) {
//         for (auto item : data.data)
//         {
//             LOG(INFO) << item.contract_code << ":" << item.volume << "/" << item.margin_mode;
//         }
//     });
//     ws.CrossSubPositions("XRP-USDT", [](const SubPositionsResponse &data) {
//         for (auto item : data.data)
//         {
//             LOG(INFO) << item.contract_code << ":" << item.volume << "/" << item.margin_mode;
//         }
//     });
//     ws.RunForever();
// }