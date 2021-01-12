#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/AccountClient.hpp"
typedef huobi_futures::linear_swap::restful::AccountClient AccountClient;

#include "config.hpp"

TEST(AccountClient, GetAccountInfo)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetAccountInfo("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol.value() << ":" << item.margin_balance;
    }

    result = acClient.CrossGetAccountInfo("USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        for (auto ct : item.contract_detail.value())
        {
            LOG(INFO) << ct.contract_code << ":" << ct.margin_available;
        }
    }
}

TEST(AccountClient, GetPositionInfo)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetPositionInfo("");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol << ":" << item.position_margin;
    }

    result = acClient.CrossGetPositionInfo();
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol << ":" << item.position_margin;
    }
}

TEST(AccountClient, GetAccountPosition)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetAccountPosition("XRP-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.margin_mode << ":" << item.margin_balance;
    }

    auto result_s = acClient.CrossGetAccountPosition("USDT");
    EXPECT_EQ(result_s->err_code.has_value(), false);

    auto item = result_s->data.value();
    LOG(INFO) << item.margin_mode << ":" << item.margin_balance;
}
