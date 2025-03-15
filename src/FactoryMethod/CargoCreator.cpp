#include "CargoTransportation.h"

//* CargoCreator class
CargoCreator::CargoCreator(const double& _distanceTravel, const double& _cargoWeight) {
    if(_distanceTravel <= 0 && _cargoWeight <= 0){
        throw std::invalid_argument("Travel distance and Cargo weight must be greater than 0. Check your input and try again!!!");
    }
    
    distanceTravel = _distanceTravel;
    cargoWeight = _cargoWeight;

    createTransports();
}

void CargoCreator::createTransports() {
    transports.emplace_back(CarCreator().getTransport());
    transports.emplace_back(TrainCreator().getTransport());
    transports.emplace_back(AirplaneCreator().getTransport());
    transports.emplace_back(ShipCreator().getTransport());
}

void CargoCreator::doAction(uint32_t transportCode, TRANSPORT_ACTIONS action) const {
    if(transportCode < 0 || transportCode >= NUMBER_OF_TRANSPORTS) {
        std::cout << "Warn: unknown transport code" << std::endl;
        return ;
    }
    switch (action)
    {
    case TRANSPORT_ACTIONS::OUTPUT_INFORMATION:
        transports[transportCode]->outputTransportInformation();
        break;
    case TRANSPORT_ACTIONS::CALCULATE_CARGO:
        std::cout << "Transport type: ";  transports[transportCode] ->outputTransportType();
        std::cout << "Total cargo price: " << std::endl
                  << "Distance: " << distanceTravel << std::endl
                  << "Cargo Weight: " << cargoWeight << std::endl
                  << "Price: " << transports[transportCode]->calculateDeliveryPrice(distanceTravel, cargoWeight) << std::endl;
        break;
    default:
        std::cout << "Error: CargoCreator::doAction has worked unexpectedly. Check your code!!!";
        break;
    }
}

void CargoCreator::outputTransportInformation(uint32_t transportCode) const{
    doAction(transportCode, TRANSPORT_ACTIONS::OUTPUT_INFORMATION);
}

void CargoCreator::calculateCargoPrice(uint32_t transportCode) const{
    doAction(transportCode, TRANSPORT_ACTIONS::CALCULATE_CARGO);
}