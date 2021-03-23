#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/AccountClient.hpp"
typedef huobi_futures::linear_swap::restful::AccountClient AccountClient;
#include "huobi_futures/utils/convert.hpp"

#include "config.hpp"

TEST(AccountClient, GetBalanceValuation)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetBalanceValuation("cny");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.valuation_asset << ":" << item.balance;
    }
}

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

    result = acClient.IsolatedGetAccountInfo("BTC-USDT", string_to_long(config["SubUid"]));
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

    result = acClient.CrossGetAccountInfo("USDT", string_to_long(config["SubUid"]));
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        if (!item.contract_detail.has_value())
        {
            continue;
        }

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
    auto result = acClient.IsolatedGetPositionInfo("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol << ":" << item.position_margin;
    }

    result = acClient.IsolatedGetPositionInfo("BTC-USDT", string_to_long(config["SubUid"]));
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol << ":" << item.position_margin;
    }

    result = acClient.CrossGetPositionInfo("BTC-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.symbol << ":" << item.position_margin;
    }

    result = acClient.CrossGetPositionInfo("BTC-USDT", string_to_long(config["SubUid"]));
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

TEST(AccountClient, SetSubAuth)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.SetSubAuth(config["SubUid"], 1);
    EXPECT_EQ(result->err_code.has_value(), false);

    LOG(INFO) << "successes:" << result->data.value().successes;
    for (auto item : result->data.value().errors)
    {
        LOG(INFO) << item.sub_uid << ":" << item.err_msg;
    }
}

TEST(AccountClient, GetSubAccountList)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetSubAccountList("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.sub_uid;
        for (auto at : item.list)
        {
            LOG(INFO) << at.contract_code.value() << ":" << at.margin_balance << "/" << at.margin_mode << "/" << at.margin_account;
        }
    }

    result = acClient.CrossGetSubAccountList("usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.sub_uid;
        for (auto at : item.list)
        {
            LOG(INFO) << at.margin_balance << "/" << at.margin_mode << "/" << at.margin_account;
        }
    }
}

TEST(AccountClient, GetSubAccountInfoList)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetSubAccountInfoList("btc-usdt", 1, 20);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().sub_list)
    {
        LOG(INFO) << item.sub_uid;
        for (auto at : item.account_info_list)
        {
            LOG(INFO) << at.contract_code.value() << ":" << at.margin_balance << "/" << at.margin_mode << "/" << at.margin_account;
        }
    }

    result = acClient.CrossGetSubAccountInfoList("usdt", 1, 20);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().sub_list)
    {
        LOG(INFO) << item.sub_uid;
        for (auto at : item.account_info_list)
        {
            LOG(INFO) << at.margin_balance << "/" << at.margin_mode << "/" << at.margin_account;
        }
    }
}

TEST(AccountClient, GetFinancialRecord)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetFinancialRecord("btc-usdt", "btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().financial_record)
    {
        LOG(INFO) << item.asset << "/" << item.amount;
    }
}


TEST(AccountClient, GetFinancialRecordExact)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetFinancialRecordExact("btc-usdt", "btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().financial_record.data)
    {
        LOG(INFO) << item.asset << "/" << item.amount;
    }
}

TEST(AccountClient, GetUserSettlementRecords)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetUserSettlementRecords("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().settlement_records)
    {
        LOG(INFO) << item.contract_code << "/" << item.margin_balance << "/" << item.margin_mode;
    }

    auto result_c = acClient.CrossGetUserSettlementRecords("usdt");
    EXPECT_EQ(result_c->err_code.has_value(), false);
    for (auto item : result_c->data.value().settlement_records)
    {
        LOG(INFO) << item.margin_balance << "/" << item.margin_mode;
    }
}

TEST(AccountClient, GetAvailableLevelRate)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetAvailableLevelRate("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.available_level_rate << "/" << item.margin_mode;
    }

    result = acClient.CrossGetAvailableLevelRate("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.available_level_rate << "/" << item.margin_mode;
    }
}

TEST(AccountClient, GetOrderLimit)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetOrderLimit("limit", "btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().list)
    {
        LOG(INFO) << item.contract_code << "/" << item.open_limit << "/" << item.close_limit;
    }
}

TEST(AccountClient, GetFee)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetFee("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.open_taker_fee << "/" << item.close_taker_fee;
    }
}

TEST(AccountClient, GetTransferLimit)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetTransferLimit("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code.value() << "/" << item.transfer_in_max_daily << "/" << item.margin_mode;
    }

    result = acClient.CrossGetTransferLimit("usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.transfer_in_max_daily << "/" << item.margin_mode;
    }
}

TEST(AccountClient, GetPositionLimit)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.IsolatedGetPositionLimit("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.buy_limit << "/" << item.margin_mode;
    }

    result = acClient.CrossGetPositionLimit("btc-usdt");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value())
    {
        LOG(INFO) << item.contract_code << "/" << item.buy_limit << "/" << item.margin_mode;
    }
}

TEST(AccountClient, MasterSubTransfer)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.MasterSubTransfer(config["SubUid"], "usdt", "usdt", "usdt", 1, "sub_to_master");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}

TEST(AccountClient, GetMasterSubTransferRecord)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetMasterSubTransferRecord("usdt", 90);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().data.transfer_record)
    {
        LOG(INFO) << item.asset << "/" << item.amount << "/" << item.from_margin_account << "->" << item.to_margin_account;
    }
}

TEST(AccountClient, TransferInner)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.TransferInner("usdt", "btc-usdt", "usdt", 1);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}

TEST(AccountClient, GetApiTradingStatus)
{
    extern map<string, string> config;
    init_config();
    AccountClient acClient(config["AccessKey"], config["SecretKey"]);
    auto result = acClient.GetApiTradingStatus();
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().is_disable;
}