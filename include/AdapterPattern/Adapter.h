// Adapter.h
#ifndef ADAPTER_H
#define ADAPTER_H

#include "LegacyOrderSystem.h"
#include "PaymentOrder.h"
#include <string>
#include <stdexcept>

class Adapter : public PaymentOrder {
private:
    LegacyOrderSystem legacySystem;

    //* helper parser functions
    int parseOrderId(const std::string& details) const;
    std::string parseCustomerName(const std::string& details) const;
    double parseAmount(const std::string& details) const;
    std::string parseCurrency(const std::string& details) const;

public:
    explicit Adapter(const LegacyOrderSystem& legacy) : legacySystem(legacy) {}
    explicit Adapter(LegacyOrderSystem&& legacy) : legacySystem(std::move(legacy)) {}

    int getOrderId() const override;
    std::string getCustomerName() const override;
    double getAmount() const override;
    std::string getCurrency() const override;
};

#endif // ADAPTER_H