// PaymentOrder.h
#ifndef PAYMENT_ORDER_H
#define PAYMENT_ORDER_H

#include <string>

class PaymentOrder {
public:
    virtual int getOrderId() const = 0;
    virtual std::string getCustomerName() const = 0;
    virtual double getAmount() const = 0;
    virtual std::string getCurrency() const = 0;
    virtual ~PaymentOrder() = default;
};

#endif // PAYMENT_ORDER_H