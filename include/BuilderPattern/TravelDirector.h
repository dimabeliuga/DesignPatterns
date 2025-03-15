#ifndef TRAVEL_DIRECTOR_H
#define TRAVEL_DIRECTOR_H

#include "TravelBuilder.h"
#include <memory>

class TravelDirector{
    private: 
        std::unique_ptr<TravelBuilder> builder;
    public:
        TravelDirector(std::unique_ptr<TravelBuilder>&& builderSpecific) 
                        : builder{std::move(builderSpecific)} {}
        
        void constructTravel();
        void typeTravelInformation() const;
        Travel getConstuctedTravel() const;
};
/*
//* expamle of using this programme
auto beachBuilder = std::make_unique<AdventureTourBuilder>();
    TravelDirector director(std::move(beachBuilder));
    
    director.constructTravel();
    Travel travel = director.getConstuctedTravel();
    travel.type();
    director.typeTravelInformation();
*/

#endif //TRAVEL_DIRECTOR_H