add_executable(example main.cpp)
target_link_libraries(example curl glog::glog huobi_futures)
