#include <gtest/gtest.h>

#include "huobi_futures/linear_swap/restful/TransferClient.hpp"
typedef huobi_futures::linear_swap::restful::TransferClient TransferClient;

#include "config.hpp"

extern int my_argc;
extern char** my_argv;
TEST(TransferClient, Transfer)
{
    extern map<string, string> config;
    init_config();
    
    TransferClient tfClient(config["AccessKey"], config["SecretKey"]);
    auto result = tfClient.Transfer("linear-swap", "spot", "usdt", 1, "usdt");
    LOG(INFO) << result->success << ":" << result->message;
    EXPECT_EQ(result->code, 200);
}