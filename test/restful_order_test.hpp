#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/OrderClient.hpp"
typedef huobi_futures::linear_swap::restful::OrderClient OrderClient;

#include "config.hpp"

TEST(OrderClient, SwitchLeverRate)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedSwitchLeverRate("XRP-USDT", 10);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().lever_rate;

    result = odClient.CrossSwitchLeverRate("XRP-USDT", 10);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().lever_rate;
}

long id1 = 0;
TEST(OrderClient, PlaceOrder)
{
    extern map<string, string> config;
    init_config();
    PlaceOrderRequest pr;
    pr.contract_code = "XRP-USDT";
    pr.price = 0.5;
    pr.direction = "buy";
    pr.offset = "open";
    pr.lever_rate = 10;
    pr.volume = 1;
    pr.order_price_type = "limit";

    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedPlaceOrder(pr);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
    id1 = result->data.value().order_id;

    result = odClient.CrossPlaceOrder(pr);
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}

TEST(OrderClient, GetOrderInfo)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);
    auto result = odClient.IsolatedGetOrderInfo("XRP-USDT", "790522296375869442");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->status;

    result = odClient.CrossGetOrderInfo("XRP-USDT", "790522454593404928");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().data()->status;
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

TEST(OrderClient, CancelOrder)
{
    extern map<string, string> config;
    init_config();
    OrderClient odClient(config["AccessKey"], config["SecretKey"]);

    stringstream str_buf;
    str_buf << id1;
    auto result = odClient.IsolatedCancelOrder("XRP-USDT", str_buf.str());
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;

    str_buf.clear();
    result = odClient.CrossCancelOrder("XRP-USDT");
    EXPECT_EQ(result->data.value().errors.size(), 0);
    LOG(INFO) << result->data.value().successes;
}
