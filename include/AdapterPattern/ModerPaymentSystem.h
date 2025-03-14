// ModernPaymentSystem.h
#ifndef MODERN_PAYMENT_SYSTEM_H
#define MODERN_PAYMENT_SYSTEM_H

#include "PaymentOrder.h"
#include <map>
#include <iostream>
#include <stdexcept>

class ModernPaySystem {
private:
    std::map<std::string, double> exchangeRates = {
        {"USD", 1.0},
        {"EUR", 1.1},
        {"GBP", 1.3}
    };

public:
    void processPayment(const PaymentOrder& order) const {
        if (order.getAmount() <= 0) {
            throw std::invalid_argument("Invalid payment amount");
        }
        // Any courency expect usd will be converted to usd
        double amountInUSD = order.getAmount();
        auto rateIt = exchangeRates.find(order.getCurrency());
        if (rateIt == exchangeRates.end()) {
            throw std::invalid_argument("Unsupported currency: " + order.getCurrency());
        }
        amountInUSD /= rateIt->second;

        std::cout << "Processing payment for order " << order.getOrderId()
                  << " by " << order.getCustomerName()
                  << ". Amount: " << order.getAmount() << " " << order.getCurrency()
                  << " (Converted to USD: " << amountInUSD << " USD)" << std::endl;
    }
};

#endif // MODERN_PAYMENT_SYSTEM_H