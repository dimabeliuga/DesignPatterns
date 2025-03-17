// LegacyOrderSystem.h
#ifndef LEGACY_ORDER_SYSTEM_H
#define LEGACY_ORDER_SYSTEM_H

#include <string>

class LegacyOrderSystem {
protected:
    std::string orderDetails;
public:
    LegacyOrderSystem() = default;
    explicit LegacyOrderSystem(const std::string_view temp_orderDetails)
        : orderDetails(temp_orderDetails) {}
    
    LegacyOrderSystem(LegacyOrderSystem&&) noexcept = default;
    LegacyOrderSystem& operator=(LegacyOrderSystem&&) noexcept = default;
    LegacyOrderSystem(const LegacyOrderSystem&) = default;
    LegacyOrderSystem& operator=(const LegacyOrderSystem&) = default;
    
    virtual ~LegacyOrderSystem() = default;
    
    void setOrderDetails(const std::string_view order) {
        orderDetails = order;
    }
    std::string getOrderDetails() const { 
        return orderDetails;
    }
};

#endif // LEGACY_ORDER_SYSTEM_H