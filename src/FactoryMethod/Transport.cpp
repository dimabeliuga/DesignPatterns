#include <iostream>
#include "Transport.h"
#include "TransportDescription.h"

//* abstract Transport class
Transport::Transport(double _baseRate, double _ratePerKm, double _ratePerKg)
            : baseRate(_baseRate), ratePerKm(_ratePerKm), ratePerKg(_ratePerKg)
            { 
            }
double Transport::calculateDeliveryPrice(double distance, double cargoWeight){
    return baseRate + (distance + ratePerKm) + (cargoWeight + ratePerKm);
}

//* Car class
void Car::outputTransportInformation() const {
    std::cout << transportDescription::Car;
}
void Car::outputTransportType() const {
    std::cout << transportDescription::CarType;
}
//* Train class
void Train::outputTransportInformation() const {
    std::cout << transportDescription::Train;
}
void Train::outputTransportType() const {
    std::cout << transportDescription::TrainType;
}
//* Airplane class
void Airplane::outputTransportInformation() const {
    std::cout << transportDescription::Airplane;
}
void Airplane::outputTransportType() const {
    std::cout << transportDescription::AirplaneType;
}
//* Ship class
void Ship::outputTransportInformation() const {
    std::cout << transportDescription::Ship;
}
void Ship::outputTransportType() const {
    std::cout << transportDescription::ShipType;
}
