#include <iostream>
#include "huobi_futures/linear_swap/restful/MarketClient.hpp"
typedef huobi_futures::linear_swap::restful::MarketClient MarketClient;

int main(int argc, char* argv[])
{
    MarketClient mkClient;
    auto data = mkClient.GetContractInfo("BTC-USDT");
    std::cout << data->status << std::endl;
}