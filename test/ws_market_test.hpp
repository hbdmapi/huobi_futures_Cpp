#include <gtest/gtest.h>

#include "config.hpp"
#include <thread>
#include <chrono>

#include "huobi_futures/linear_swap/ws/WSMarketClinet.hpp"
typedef huobi_futures::linear_swap::ws::WSMarketClient WSMarketClient;

TEST(WSMarketClient, SubKLine)
{
    extern map<string, string> config;
    init_config();

    WSMarketClient ws;
    ws.SubKLine("BTC-USDT", "1min", [](const SubKLineResponse &data) {
        LOG(INFO) << data.tick.close;
    });
    ws.RunForever();
}

TEST(WSMarketClient, ReqKLine)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.ReqKLine("BTC-USDT", "1min", 1608727852, 1608727882, [](const ReqKLineResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.close;
        }
    });
    ws.RunForever();
}

TEST(WSMarketClient, SubDepth)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.SubDepth("BTC-USDT", "step0", [](const SubDepthResponse &data) {
        for (auto item : data.tick.asks)
        {
            LOG(INFO) << *item.begin() << "/" << *(item.begin() + 1);
        }
    });
    ws.RunForever();
}