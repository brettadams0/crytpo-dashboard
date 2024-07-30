#include "alerts.h"

CryptoAlerts::CryptoAlerts(double threshold) : threshold(threshold) {}

bool CryptoAlerts::check_alert(double current_price, double previous_price) {
    if (previous_price == 0) return false;
    double change_percentage = std::abs(current_price - previous_price) / previous_price * 100;
    return change_percentage >= threshold;
}
