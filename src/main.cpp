#include "TravelDirector.h"
#include "Builders.h"
#include <memory>

int main() {
    auto beachBuilder = std::make_unique<AdventureTourBuilder>();
    TravelDirector director(std::move(beachBuilder));
    
    director.constructTravel();
    Travel travel = director.getConstuctedTravel();
    travel.type();
    director.typeTravelInformation();
    
    return 0;
}