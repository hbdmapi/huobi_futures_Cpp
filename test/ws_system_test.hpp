#include <gtest/gtest.h>

#include "config.hpp"
#include <thread>
#include <chrono>

#include "huobi_futures/linear_swap/ws/WSSystemClient.hpp"
typedef huobi_futures::linear_swap::ws::WSSystemClient WSSystemClient;

TEST(WSSystemClient, SubHeartbeat)
{
    extern map<string, string> config;
    init_config();

    WSSystemClient ws("api.hbdm.com");
    ws.SubHeartbeat("linear-swap", [](const SubHeartbeatResponse &data) {
        LOG(INFO) << data.data.value().estimated_recovery_time << "/" << data.data.value().estimated_recovery_time;
    });
    std::this_thread::sleep_for(std::chrono::seconds(60 * 3));
}