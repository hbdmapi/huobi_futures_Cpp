#include <gtest/gtest.h>

#include "config.hpp"

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
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
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
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
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
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSMarketClient, SubDepthIncremental)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.SubDepthIncremental("BTC-USDT", "size_20", [](const SubDepthResponse &data) {
        for (auto item : data.tick.asks)
        {
            LOG(INFO) << *item.begin() << "/" << *(item.begin() + 1);
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSMarketClient, SubMarketDetail)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.SubMarketDetail("BTC-USDT", [](const SubMarketDetailResponse &data) {
        LOG(INFO) << data.tick.open  << "/" << data.tick.close;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSMarketClient, SubBbo)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.SubBbo("BTC-USDT", [](const SubBboResponse &data) {
        LOG(INFO) << data.tick.ask[0] << "/" << data.tick.ask[1];
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSMarketClient, ReqTradeDetail)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.ReqTradeDetail("BTC-USDT", [](const ReqTradeDetailResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.amount << "/" << item.price;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSMarketClient, SubTradeDetail)
{
    extern map<string, string> config;
    init_config();
    WSMarketClient ws;
    ws.SubTradeDetail("BTC-USDT", [](const SubTradeDetailResponse &data) {
        for (auto item : data.tick.data)
        {
            LOG(INFO) << item.amount << "/" << item.price;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}
