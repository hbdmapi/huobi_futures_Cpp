#include <gtest/gtest.h>
#include "restful_market_test.hpp"
#include "restful_account_test.hpp"
#include "restful_order_test.hpp"
#include "restful_trigger_order_test.hpp"
#include "restful_transfer_test.hpp"
#include "ws_market_test.hpp"
#include "ws_notify_test.hpp"

int my_argc;
char** my_argv;
int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    my_argc = argc;
    my_argv = argv;
    return RUN_ALL_TESTS();
}