// Adapter.cpp
#include "Adapter.h"

int Adapter::parseOrderId(const std::string& details) const {
    size_t pos = details.find("OrderID: ");
    if (pos == std::string::npos) throw std::runtime_error("OrderID not found");
    pos += 9; //* Order id length
    size_t end = details.find(';', pos);
    return std::stoi(details.substr(pos, end - pos));
}

std::string Adapter::parseCustomerName(const std::string& details) const {
    size_t pos = details.find("Customer: ");
    if (pos == std::string::npos) throw std::runtime_error("Customer not found");
    pos += 10; //* Customer required length
    size_t end = details.find(';', pos);
    return details.substr(pos, end - pos);
}

double Adapter::parseAmount(const std::string& details) const {
    size_t pos = details.find("Amount: ");
    if (pos == std::string::npos) throw std::runtime_error("Amount not found");
    pos += 8; //*"Amount" length
    size_t end = details.find(';', pos);
    return std::stod(details.substr(pos, end - pos));
}

std::string Adapter::parseCurrency(const std::string& details) const {
    size_t pos = details.find("Currency: ");
    if (pos == std::string::npos) throw std::runtime_error("Currency not found");
    pos += 10; //* "Currency:" length
    size_t end = details.find(';', pos);
    return details.substr(pos, end - pos);
}

int Adapter::getOrderId() const {
    return parseOrderId(legacySystem.getOrderDetails());
}

std::string Adapter::getCustomerName() const {
    return parseCustomerName(legacySystem.getOrderDetails());
}

double Adapter::getAmount() const {
    return parseAmount(legacySystem.getOrderDetails());
}

std::string Adapter::getCurrency() const {
    return parseCurrency(legacySystem.getOrderDetails());
}