enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test main.cpp)
target_link_libraries(test Threads::Threads websockets OpenSSL::SSL OpenSSL::Crypto ${GTEST_BOTH_LIBRARIES} curl z glog::glog huobi_futures)