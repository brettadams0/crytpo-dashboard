#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdexcept>
#include "data_fetcher.h"
#include "data_visualizer.h"
#include "alerts.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <crypto_id> <currency> --api_key <your_api_key> [--threshold <percentage>]" << std::endl;
        return 1;
    }

    std::string crypto_id = argv[1];
    std::string currency = argv[2];
    std::string api_key;
    double threshold = 5.0;

    for (int i = 3; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--api_key") {
            if (i + 1 < argc) {
                api_key = argv[++i];
            } else {
                std::cerr << "Error: --api_key requires an argument" << std::endl;
                return 1;
            }
        } else if (arg == "--threshold") {
            if (i + 1 < argc) {
                threshold = std::stod(argv[++i]);
            } else {
                std::cerr << "Error: --threshold requires an argument" << std::endl;
                return 1;
            }
        }
    }

    if (api_key.empty()) {
        std::cerr << "Error: API key is required" << std::endl;
        return 1;
    }

    CryptoDataFetcher fetcher(api_key);
    CryptoDataVisualizer visualizer;
    CryptoAlerts alerts(threshold);

    // Fetch current price
    double price = fetcher.get_price(crypto_id, currency);
    std::cout << "Current price of " << crypto_id << " in " << currency << ": $" << price << std::endl;

    // Fetch historical data
    std::vector<std::pair<long, double>> historical_data = fetcher.get_historical_data(crypto_id, currency);
    if (!historical_data.empty()) {
        visualizer.plot_price_chart(historical_data);

        // Check for alerts
        double previous_price = historical_data.size() > 1 ? historical_data.end()[-2].second : 0;
        if (alerts.check_alert(price, previous_price)) {
            std::cout << "Alert: Significant price change detected for " << crypto_id << "." << std::endl;
        }
    } else {
        std::cout << "No historical data available." << std::endl;
    }

    return 0;
}
