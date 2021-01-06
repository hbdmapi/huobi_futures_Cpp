#include <gtest/gtest.h>
#include "huobi_futures/linear_swap/restful/MarketClient.hpp"
typedef huobi_futures::linear_swap::restful::MarketClient MarketClient;

TEST(MarketClient, GetContractInfo)
{
    MarketClient mkClient;
    auto result = mkClient.GetContractInfo();
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->contract_code;

    result = mkClient.GetContractInfo("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->contract_size;

    result = mkClient.GetContractInfo("BTC-USDT1");
    EXPECT_EQ(result->err_code.has_value(), true);
    LOG(INFO) << result->err_msg.value().data();
}

TEST(MarketClient, GetIndex)
{
    MarketClient mkClient;
    auto result = mkClient.GetIndex("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->contract_code;

    result = mkClient.GetIndex("BTC-USDT1");
    EXPECT_EQ(result->err_code.has_value(), true);
    LOG(INFO) << result->err_msg.value().data();
}

TEST(MarketClient, GetPriceLimit)
{
    MarketClient mkClient;
    auto result = mkClient.GetPriceLimit("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->contract_code;

    result = mkClient.GetPriceLimit("BTC-USDT1");
    EXPECT_EQ(result->err_code.has_value(), true);
    LOG(INFO) << result->err_msg.value().data();
}

TEST(MarketClient, GetOpenInterest)
{
    MarketClient mkClient;
    auto result = mkClient.GetOpenInterest();
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->contract_code;

    result = mkClient.GetOpenInterest("BTC-USDT1");
    EXPECT_EQ(result->err_code.has_value(), true);
    LOG(INFO) << result->err_msg.value().data();
}

TEST(MarketClient, GetDepth)
{
    MarketClient mkClient;
    auto result = mkClient.GetDepth("BTC-USDT", "step0");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto pv : result->tick.data.asks)
    {
        LOG(INFO) << *(pv.begin()) << "/" << *(pv.begin() + 1);
    }
}

TEST(MarketClient, GetKLine)
{
    MarketClient mkClient;
    auto result = mkClient.GetKLine("BTC-USDT", "1day");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->amount;
}

TEST(MarketClient, GetMerged)
{
    MarketClient mkClient;
    auto result = mkClient.GetMerged("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    auto pv = result->tick.value().ask;
    LOG(INFO) << *(pv.begin()) << "/" << *(pv.begin() + 1);
}

TEST(MarketClient, GetTrade)
{
    MarketClient mkClient;
    auto result = mkClient.GetTrade("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto pv : result->tick.data.data)
    {
        LOG(INFO) << pv.amount << "/" << pv.direction << "/" << pv.price;
    }
}

TEST(MarketClient, GetHisTrade)
{
    MarketClient mkClient;
    auto result = mkClient.GetHisTrade("BTC-USDT", 10);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto pv : result->tick.value().data)
    {
        LOG(INFO) << pv.amount << "/" << pv.direction << "/" << pv.price;
    }
}
