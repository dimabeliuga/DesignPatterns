#include "TravelDirector.h"
#include <iostream>

void TravelDirector::constructTravel() {
    if(builder == nullptr) {
        throw std::invalid_argument("The builder wasn't specified");
    }
    builder->buildFlight();
    builder->buildAccomodation();
    builder->buildMealPlan();
    builder->buildExcursions();
    builder->buildTransfer();
}
void TravelDirector::typeTravelInformation() const{
    builder->getTravel().type();
}
Travel TravelDirector::getConstuctedTravel() const{
    return builder->getTravel();
}