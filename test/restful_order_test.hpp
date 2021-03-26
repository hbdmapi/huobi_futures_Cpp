#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/OrderClient.hpp"
typedef huobi_futures::linear_swap::restful::OrderClient OrderClient;

#include "config.hpp"

extern int my_argc;
extern char** my_argv;
TEST(OrderClient, PlaceOrder)
{
    extern map<string, string> config;
    init_config();
    PlaceOrderRequest pr;
    pr.contract_code = "XRP-USDT";
    pr.price = 0.4;
    pr.direction = "buy";
    pr.offset = "open";
    pr.lever_rate = 10;
    pr.volume = 1;
    pr.order_price_type = "limit";

    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedPlaceOrder(pr);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;

    result = odClient.CrossPlaceOrder(pr);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}

TEST(OrderClient, BatchOrder)
{
    extern map<string, string> config;
    init_config();
    PlaceOrderRequest pr;
    pr.contract_code = "XRP-USDT";
    pr.price = 0.41;
    pr.direction = "buy";
    pr.offset = "open";
    pr.lever_rate = 10;
    pr.volume = 1;
    pr.order_price_type = "limit";

    std::vector<PlaceOrderRequest> bo;
    bo.push_back(pr);

    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedBatchOrder(bo);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().success)
    {
        LOG(INFO) << item.order_id;
    }

    result = odClient.CrossBatchOrder(bo);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().success)
    {
        LOG(INFO) << item.order_id;
    }
}

TEST(OrderClient, CancelOrder)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);

    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = odClient.IsolatedCancelOrder("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;

    result = odClient.IsolatedCancelOrder("XRP-USDT");
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;

    str_buf.str("");
    str_buf << my_argv[2];
    result = odClient.CrossCancelOrder("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;


    result = odClient.CrossCancelOrder("XRP-USDT");
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;
}

TEST(OrderClient, SwitchLeverRate)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedSwitchLeverRate("XRP-USDT", 20);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().lever_rate;

    result = odClient.CrossSwitchLeverRate("XRP-USDT", 20);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().lever_rate;
}

TEST(OrderClient, GetOrderInfo)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = odClient.IsolatedGetOrderInfo("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->status;

    str_buf.str("");
    str_buf << my_argv[2];
    result = odClient.CrossGetOrderInfo("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->status;
}

TEST(OrderClient, GetOrderDetail)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = odClient.IsolatedGetOrderDetail("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().contract_code << ":" << result->data.value().price
              << ":" << result->data.value().volume << ":" << result->data.value().margin_mode;

    str_buf.str("");
    str_buf << my_argv[2];
    result = odClient.CrossGetOrderDetail("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().contract_code << ":" << result->data.value().price
              << ":" << result->data.value().volume << ":" << result->data.value().margin_mode;
}

TEST(OrderClient, GetOpenOrder)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetOpenOrder("XRP-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }

    result = odClient.CrossGetOpenOrder("XRP-USDT");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }
}

TEST(OrderClient, GetHisorders)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetHisorders("XRP-USDT", 0, 1, "0", 90);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }

    result = odClient.CrossGetHisorders("XRP-USDT", 0, 1, "0", 90);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }
}

TEST(OrderClient, GetHisordersExact)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetHisordersExact("XRP-USDT", 0, 1, "0");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }

    result = odClient.CrossGetHisordersExact("XRP-USDT", 0, 1, "0");
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {
        LOG(INFO) << item.contract_code << ":" << item.price << ":" << item.volume << ":" << item.margin_mode;
    }
}

TEST(OrderClient, GetMatchResults)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetMatchResults("XRP-USDT", 0, 90);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().trades)
    {
        LOG(INFO) << item.contract_code << ":" << item.trade_price << ":" << item.trade_volume << ":" << item.margin_mode;
    }

    result = odClient.CrossGetMatchResults("XRP-USDT", 0, 90);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().trades)
    {
        LOG(INFO) << item.contract_code << ":" << item.trade_price << ":" << item.trade_volume << ":" << item.margin_mode;
    }
}

TEST(OrderClient, GetMatchResultsExact)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetMatchResultsExact("UNI-USDT", 0);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().trades)
    {
        LOG(INFO) << item.contract_code << ":" << item.trade_price << ":" << item.trade_volume << ":" << item.margin_mode;
    }

    result = odClient.CrossGetMatchResultsExact("UNI-USDT", 0);
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().trades)
    {
        LOG(INFO) << item.contract_code << ":" << item.trade_price << ":" << item.trade_volume << ":" << item.margin_mode;
    }
}

TEST(OrderClient, LightningClosePosition)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedLightningClosePosition("XRP-USDT", 1, "sell");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;

    result = odClient.CrossLightningClosePosition("XRP-USDT", 1, "sell");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}