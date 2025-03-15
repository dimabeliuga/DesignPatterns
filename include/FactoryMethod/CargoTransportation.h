#ifndef CARGO_TRANSPORTATION_H
#define CARGO_TRANSPORTATION_H

#include "TransportCreator.h"
#include "Transport.h"
#include <memory>
#include <vector>
#include <iostream>

class CargoCreator {
    private: //valuabels
        enum class TRANSPORT_ACTIONS {OUTPUT_INFORMATION = 0, CALCULATE_CARGO};
        const size_t NUMBER_OF_TRANSPORTS = 4;
        std::vector<std::unique_ptr<Transport>> transports;
        double distanceTravel;
        double cargoWeight;

    private: //functions
        void createTransports();
        void doAction(uint32_t transportCode, TRANSPORT_ACTIONS action) const;
    
    public:
        CargoCreator(const double& _distanceTravel, const double& _cargoWeight);
        void outputTransportInformation(uint32_t transportCode) const;
        void calculateCargoPrice(uint32_t transportCode) const;
};

#endif //CARGO_TRANSPORTATION_H