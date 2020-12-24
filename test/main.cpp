#include <gtest/gtest.h>
//#include "restful_market_test.hpp"
//#include "restful_account_test.hpp"
//#include "restful_order_test.hpp"
#include "ws_market_test.hpp"

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}