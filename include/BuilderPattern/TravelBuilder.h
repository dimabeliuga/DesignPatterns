#ifndef TRAVEL_BUILDER_H
#define TRAVEL_BUILDER_H

#include "Travel.h"
#include <string>


class TravelBuilder {
    protected:
        Travel travel;
    public:
        TravelBuilder() = default;
        virtual void buildFlight()       = 0;
        virtual void buildMealPlan()     = 0;
        virtual void buildTransfer()     = 0;
        virtual void buildExcursions()   = 0;
        virtual void buildAccomodation() = 0;
        const Travel& getTravel() const { return travel; }
        ~TravelBuilder() = default;
};

#endif //TRAVEL_BUILDER_H