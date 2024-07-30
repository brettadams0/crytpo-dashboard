#ifndef DATA_FETCHER_H
#define DATA_FETCHER_H

#include <string>
#include <vector>
#include <utility>

class CryptoDataFetcher {
public:
    CryptoDataFetcher(const std::string& api_key);
    double get_price(const std::string& crypto_id, const std::string& currency = "USD");
    std::vector<std::pair<long, double>> get_historical_data(const std::string& crypto_id, const std::string& currency = "USD");

private:
    std::string api_key;
    std::string base_url;
    std::string make_request(const std::string& url);
};

#endif
