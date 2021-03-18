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

TEST(MarketClient, GetMarkPriceKLine)
{
    MarketClient mkClient;
    auto result = mkClient.GetMarkPriceKLine("BTC-USDT", "1day", 1);
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

TEST(MarketClient, GetBatchMerged)
{
    MarketClient mkClient;
    auto result = mkClient.GetBatchMerged("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    auto pv = result->ticks.value()[0].ask;
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
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.ts;
        for(auto pv: item.data)
        {
            LOG(INFO) << pv.amount << "/" << pv.direction << "/" << pv.price;
        }   
    }
}

TEST(MarketClient, GetRiskInfo)
{
    MarketClient mkClient;
    auto result = mkClient.GetRiskInfo();
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.contract_code << "/" << pv.estimated_clawback << "/" << pv.insurance_fund;
    }
}

TEST(MarketClient, GetInsurancefund)
{
    MarketClient mkClient;
    auto result = mkClient.GetInsurancefund("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().tick)
    {
        LOG(INFO) << pv.insurance_fund << "/" << pv.ts;
    }
}

TEST(MarketClient, GetAdjustfactor)
{
    MarketClient mkClient;
    auto result = mkClient.IsolatedGetAdjustfactor("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto item : result->data.value())
    {
        for (auto lt : item.list)
        {
            for (auto pv : lt.ladders)
            {
                LOG(INFO) << pv.adjust_factor << "/" << pv.ladder;
            }
        }
    }

    result = mkClient.CrossGetAdjustfactor("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto item : result->data.value())
    {
        for (auto lt : item.list)
        {
            for (auto pv : lt.ladders)
            {
                LOG(INFO) << pv.adjust_factor << "/" << pv.ladder;
            }
        }
    }
}

TEST(MarketClient, GetEstimatedSettlementPrice)
{
    MarketClient mkClient;
    auto result = mkClient.GetEstimatedSettlementPrice("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.estimated_settlement_price.data;
    }
}


TEST(MarketClient, GetHisOpenInterest)
{
    MarketClient mkClient;
    auto result = mkClient.GetHisOpenInterest("BTC-USDT", "1day", 1);
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().tick)
    {
        LOG(INFO) << pv.value << "/" << pv.value;
    }
}

TEST(MarketClient, GetLadderMargin)
{
    MarketClient mkClient;
    auto result = mkClient.IsolatedGetLadderMargin("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto item : result->data.value())
    {
        for (auto pv : item.list)
        {
            LOG(INFO) << pv.lever_rate;
        }
    }

    result = mkClient.CrossGetLadderMargin("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        for (auto pv : item.list)
        {
            LOG(INFO) << pv.lever_rate;
        }
    }
}

TEST(MarketClient, GetEliteRatio)
{
    MarketClient mkClient;
    auto result = mkClient.GetEliteAccountRatio("BTC-USDT", "5min");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().list)
    {
        LOG(INFO) << pv.buy_ratio << "/" << pv.sell_ratio;
    }
}

TEST(MarketClient, GetApiStatus)
{
    MarketClient mkClient;
    auto result = mkClient.IsolatedGetApiStatus("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.contract_code << "/" << pv.margin_mode << "/" << pv.margin_account;
    }
}

TEST(MarketClient, CrossGetTransferStatus)
{
    MarketClient mkClient;
    auto result = mkClient.CrossGetTransferStatus("USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.margin_mode << "/" << pv.margin_account;
    }
}

TEST(MarketClient, CrossGetTradeStatus)
{
    MarketClient mkClient;
    auto result = mkClient.CrossGetTradeStatus("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.contract_code << "/" << pv.margin_mode << "/" << pv.margin_account;
    }
}

TEST(MarketClient, GetFundingRate)
{
    MarketClient mkClient;
    auto result = mkClient.GetFundingRate("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    LOG(INFO) << result->data.value().contract_code << "/" << result->data.value().funding_rate << "/" << result->data.value().funding_time;
}

TEST(MarketClient, GetHisFundingRate)
{
    MarketClient mkClient;
    auto result = mkClient.GetHisFundingRate("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().data)
    {
        LOG(INFO) << pv.contract_code << "/" << pv.funding_rate << "/" << pv.funding_time;
    }
}

TEST(MarketClient, GetLiquidationOrders)
{
    MarketClient mkClient;
    auto result = mkClient.GetLiquidationOrders("BTC-USDT", 0, 7);
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().orders)
    {
        LOG(INFO) << pv.contract_code << "/" << pv.direction << "/" << pv.offset << "/" << pv.price << "/" << pv.volume;
    }
}

TEST(MarketClient, GetSettlementRecords)
{
    MarketClient mkClient;
    auto result = mkClient.GetSettlementRecords("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value().settlement_record)
    {
        LOG(INFO) << pv.contract_code << "/" << pv.settlement_price << "/" << pv.settlement_type;
    }
}

TEST(MarketClient, GetPremiumIndexKlineResponse)
{
    MarketClient mkClient;
    auto result = mkClient.GetPremiumIndexKlineResponse("BTC-USDT", "1min", 1);
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.vol << "/" << pv.count << "/" << pv.amount;
    }
}

TEST(MarketClient, GetEstimatedRateKlineResponse)
{
    MarketClient mkClient;
    auto result = mkClient.GetEstimatedRateKlineResponse("BTC-USDT", "1min", 1);
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.vol << "/" << pv.count << "/" << pv.amount;
    }
}

TEST(MarketClient, GetBasis)
{
    MarketClient mkClient;
    auto result = mkClient.GetBasis("BTC-USDT", "1min");
    EXPECT_EQ(result->err_code.has_value(), false);

    for (auto pv : result->data.value())
    {
        LOG(INFO) << pv.contract_price << "/" << pv.index_price << "/" << pv.basis;
    }
}
