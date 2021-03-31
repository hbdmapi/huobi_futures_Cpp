#include <gtest/gtest.h>

#include "config.hpp"

#include "huobi_futures/linear_swap/ws/WSIndexClinet.hpp"
typedef huobi_futures::linear_swap::ws::WSIndexClient WSIndexClient;

TEST(WSIndexClient, SubIndex)
{
    extern map<string, string> config;
    init_config();

    WSIndexClient ws;
    ws.SubIndex("BTC-USDT", "1min", [](const SubIndexResponse &data) {
        LOG(INFO) << data.tick.close;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, ReqIndex)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.ReqIndex("BTC-USDT", "1min", 1608727852, 1608727882, [](const ReqIndexResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.close;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, SubPremiumIndex)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.SubPremiumIndex("BTC-USDT", "1min", [](const SubStrKlineResponse &data) {
        LOG(INFO) << data.tick.amount << "/" << data.tick.close;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, ReqPremiumIndex)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.ReqPremiumIndex("BTC-USDT", "1min", 1608727852, 1608727882, [](const ReqStrKlineResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.close;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, SubEstimatedRate)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.SubEstimatedRate("BTC-USDT", "1min", [](const SubStrKlineResponse &data) {
        LOG(INFO) << data.tick.amount << "/" << data.tick.close;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, ReqEstimatedRate)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.ReqEstimatedRate("BTC-USDT", "1min", 1608727852, 1608727882, [](const ReqStrKlineResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.close;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, SubBasis)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.SubBasis("BTC-USDT", "1min", "open", [](const SubBasisResponse &data) {
        LOG(INFO) << data.tick.index_price  << "/" << data.tick.basis;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, ReqBasis)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.ReqBasis("BTC-USDT", "1min", "open", 1608727852, 1608727882, [](const ReqBasisResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.basis;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, SubMarkPrice)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.SubMarkPrice("BTC-USDT", "1min", [](const SubStrKlineResponse &data) {
        LOG(INFO) << data.tick.close << "/" << data.tick.count;
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}

TEST(WSIndexClient, ReqMarkPrice)
{
    extern map<string, string> config;
    init_config();
    WSIndexClient ws;
    ws.ReqMarkPrice("BTC-USDT", "1min", 1608727852, 1608727882, [](const ReqStrKlineResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.amount << "/" << item.close;
        }
    });
   std::this_thread::sleep_for(std::chrono::seconds(60 * 1));
}
