#ifndef ALERTS_H
#define ALERTS_H

class CryptoAlerts {
public:
    CryptoAlerts(double threshold);
    bool check_alert(double current_price, double previous_price);

private:
    double threshold;
};

#endif
