#include "data_fetcher.h"
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <sstream>

using json = nlohmann::json;

CryptoDataFetcher::CryptoDataFetcher(const std::string& api_key) 
    : api_key(api_key), base_url("https://pro-api.coinmarketcap.com/v1/cryptocurrency") {}

std::string CryptoDataFetcher::make_request(const std::string& url) {
    CURL* curl;
    CURLcode res;
    std::string read_buffer;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, +[](void* contents, size_t size, size_t nmemb, void* userp) {
            ((std::string*)userp)->append((char*)contents, size * nmemb);
            return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &read_buffer);
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("X-CMC_PRO_API_KEY: " + api_key).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return read_buffer;
}

double CryptoDataFetcher::get_price(const std::string& crypto_id, const std::string& currency) {
    std::string url = base_url + "/quotes/latest?symbol=" + crypto_id + "&convert=" + currency;
    std::string response = make_request(url);
    auto data = json::parse(response);
    return data["data"][crypto_id]["quote"][currency]["price"];
}

std::vector<std::pair<long, double>> CryptoDataFetcher::get_historical_data(const std::string& crypto_id, const std::string& currency) {
    std::string url = base_url + "/historical?symbol=" + crypto_id + "&convert=" + currency;
    std::string response = make_request(url);
    auto data = json::parse(response);
    std::vector<std::pair<long, double>> historical_data;
    for (const auto& item : data["data"]) {
        historical_data.emplace_back(item["time"].get<long>(), item["price"].get<double>());
    }
    return historical_data;
}
