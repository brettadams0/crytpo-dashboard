#include "data_visualizer.h"
#include <matplotlibcpp.h>
#include <vector>
#include <chrono>
#include <iomanip>

namespace plt = matplotlibcpp;

void CryptoDataVisualizer::plot_price_chart(const std::vector<std::pair<long, double>>& data) {
    std::vector<double> timestamps;
    std::vector<double> prices;
    for (const auto& item : data) {
        timestamps.push_back(static_cast<double>(item.first));
        prices.push_back(item.second);
    }
    plt::figure_size(1200, 600);
    plt::plot(timestamps, prices, "o-");
    plt::title("Cryptocurrency Price Over Time");
    plt::xlabel("Date");
    plt::ylabel("Price (USD)");
    plt::grid(true);
    plt::show();
}
