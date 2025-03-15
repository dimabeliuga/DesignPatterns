#include "TransportCreator.h"

//* CarCreator 
std::unique_ptr<Transport> CarCreator::getTransport() {
    return std::make_unique<Car>();
}

//* TrainCreator
std::unique_ptr<Transport> TrainCreator::getTransport() {
    return std::make_unique<Train>();
}

//* AirplaneCreator 
std::unique_ptr<Transport> AirplaneCreator::getTransport() {
    return std::make_unique<Airplane>();
}

//* ShipCreator
std::unique_ptr<Transport> ShipCreator::getTransport() {
    return std::make_unique<Ship>();
}
