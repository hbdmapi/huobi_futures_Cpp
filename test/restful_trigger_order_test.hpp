#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/TriggerOrderClient.hpp"
typedef huobi_futures::linear_swap::restful::TriggerOrderClient TriggerOrderClient;

#include "huobi_futures/utils/convert.hpp"

#include "config.hpp"

extern int my_argc;
extern char **my_argv;
TEST(TriggerOrderClient, TriggerOrder)
{
    extern map<string, string> config;
    init_config();

    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedTriggerOrder("xrp-usdt", "le", 0.5, 1, "buy", "open", 10, 0.5, "limit");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;

    result = todClient.CrossTriggerOrder("xrp-usdt", "le", 0.5, 1, "buy", "open", 10, 0.5, "limit");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().order_id;
}

TEST(TriggerOrderClient, CancelTriggerOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);

    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = todClient.IsolatedCancelTriggerOrder("xrp-usdt", str_buf.str());
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    result = todClient.IsolatedCancelTriggerOrder("xrp-usdt", "", "buy", "open");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    str_buf.str("");
    str_buf << my_argv[2];
    result = todClient.CrossCancelTriggerOrder("xrp-usdt", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    result = todClient.CrossCancelTriggerOrder("xrp-usdt", "", "buy", "open");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;
}

TEST(TriggerOrderClient, GetTriggerOpenOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedGetTriggerOpenOrder("xrp-usdt", 1, 10, 0);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }

    result = todClient.CrossGetTriggerOpenOrder("xrp-usdt", 1, 10, 0);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }
}

TEST(TriggerOrderClient, GetTriggerHisorders)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedGetTriggerHisorders("xrp-usdt", 0, "0", 90, 1, 10, "created_at");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }

    result = todClient.CrossGetTriggerHisorders("xrp-usdt", 0, "0", 90, 1, 10, "created_at");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }
}

TEST(TriggerOrderClient, TpslOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedTpslOrder("xrp-usdt", "buy", 1, 0.3, 0.3, "limit", 0.6, 0.6, "limit");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    auto item = result->data.value();
    LOG(INFO) << item.sl_order.value().order_id << "/" << item.tp_order.value().order_id;

    result = todClient.CrossTpslOrder("xrp-usdt", "buy", 1, 0.3, 0.3, "limit", 0.6, 0.6, "limit");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    item = result->data.value();
    LOG(INFO) << item.sl_order.value().order_id << "/" << item.tp_order.value().order_id;
}

TEST(TriggerOrderClient, CancelTpslOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);

    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = todClient.IsolatedCancelTpslOrder("xrp-usdt", str_buf.str());
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    result = todClient.IsolatedCancelTpslOrder("xrp-usdt", "", "buy");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    str_buf.str("");
    str_buf << my_argv[2];
    result = todClient.CrossCancelTpslOrder("xrp-usdt", str_buf.str());
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;

    result = todClient.CrossCancelTpslOrder("xrp-usdt", "", "buy");
    EXPECT_EQ(result->err_code.has_value(), false);
    LOG(INFO) << result->data.value().successes;
}

TEST(TriggerOrderClient, GetTpslOpenOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedGetTpslOpenOrder("xrp-usdt", 1, 10, 0);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }

    result = todClient.CrossGetTpslOpenOrder("xrp-usdt", 1, 10, 0);
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }
}

TEST(TriggerOrderClient, GetTpslHisorders)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    auto result = todClient.IsolatedGetTpslHisorders("xrp-usdt", "0", 90, 1, 20, "created_at");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }

    result = todClient.CrossGetTpslHisorders("xrp-usdt", "0", 90, 1, 20, "created_at");
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    for (auto item : result->data.value().orders)
    {

        LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
    }
}

TEST(TriggerOrderClient, GetRelationTpslOrder)
{
    extern map<string, string> config;
    init_config();
   
    TriggerOrderClient todClient(config["AccessKey"], config["SecretKey"]);
    stringstream str_buf;
    str_buf << my_argv[1];
    auto result = todClient.IsolatedGetRelationTpslOrder("xrp-usdt", string_to_long(str_buf.str()));
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    auto item = result->data.value();
    LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;

    str_buf.str("");
    str_buf << my_argv[2];
    result = todClient.IsolatedGetRelationTpslOrder("xrp-usdt", string_to_long(str_buf.str()));
    if (result->err_msg.has_value())
    {
        LOG(ERROR) << result->err_msg.value();
    }
    EXPECT_EQ(result->err_code.has_value(), false);
    item = result->data.value();
    LOG(INFO) << item.contract_code << ":" << item.order_id << ":" << item.margin_mode;
}