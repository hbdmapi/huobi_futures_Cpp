#include <gtest/gtest.h>

#include "config.hpp"
#include <thread>
#include <chrono>

#include "huobi_futures/linear_swap/ws/WSNotifyClinet.hpp"
typedef huobi_futures::linear_swap::ws::NotifyClient NotifyClient;

TEST(NotifyClient, SubOrders)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubOrders("DOGE-USDT", [](const SubOrdersResponse &data) {
        LOG(INFO) << data.margin_asset << "/" << data.margin_mode;
    });
    ws.CrossSubOrders("DOGE-USDT", [](const SubOrdersResponse &data) {
        LOG(INFO) << data.margin_asset << "/" << data.margin_mode;
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubAccounts)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubAccounts("DOGE-USDT", [](const SubAccountsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.margin_mode << ":" << item.contract_code.value() << "/" << item.margin_balance;
        }
    });
    ws.CrossSubAccounts("USDT", [](const SubAccountsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.margin_mode << ":" << item.margin_asset << "/" << item.margin_balance;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubPositions)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubPositions("DOGE-USDT", [](const SubPositionsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.direction << "/" << item.volume << "/" << item.margin_mode;
        }
    });
    ws.CrossSubPositions("DOGE-USDT", [](const SubPositionsResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.direction << "/" << item.volume << "/" << item.margin_mode;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubMatchOrders)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubMatchOrders("DOGE-USDT", [](const SubMatchOrdersResponse &data) {
        for (auto item : data.trade)
        {
            LOG(INFO) << item.trade_id << ":" << item.trade_price << "/" << item.trade_volume;
        }
    });
    ws.CrossSubMatchOrders("DOGE-USDT", [](const SubMatchOrdersResponse &data) {
        for (auto item : data.trade)
        {
            LOG(INFO) << item.trade_id << ":" << item.trade_price << "/" << item.trade_volume;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubLiquidationOrders)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.SubLiquidationOrders("*", [](const SubLiquidationOrdersResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.price << "/" << item.volume;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubFundingRateOrders)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.SubFundingRateOrders("xrp-usdt", [](const SubFundingRateResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.funding_rate << "/" << item.funding_time;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubContractInfoOrders)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.SubContractInfoOrders("DOGE-USDT", [](const SubContractInfoResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.contract_size << "/" << item.contract_status;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}

TEST(NotifyClient, SubTriggerOrder)
{
    extern map<string, string> config;
    init_config();

    NotifyClient ws(config["AccessKey"], config["SecretKey"]);
    ws.IsolatedSubTriggerOrder("*", [](const SubTriggerOrderResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.order_price << "/" << item.volume;
        }
    });
    ws.CrossSubTriggerOrder("*", [](const SubTriggerOrderResponse &data) {
        for (auto item : data.data)
        {
            LOG(INFO) << item.contract_code << ":" << item.order_price << "/" << item.volume;
        }
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}