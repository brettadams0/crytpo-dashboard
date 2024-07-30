#ifndef DATA_VISUALIZER_H
#define DATA_VISUALIZER_H

#include <vector>
#include <utility>

class CryptoDataVisualizer {
public:
    void plot_price_chart(const std::vector<std::pair<long, double>>& data);
};

#endif
