#ifndef BUILDERS_H
#define BUILDERS_H

#include "TravelBuilder.h"

class BeachVacationBuilder : public TravelBuilder {
    public:
    void buildFlight()       override;
    void buildMealPlan()     override;
    void buildTransfer()     override;
    void buildExcursions()   override;
    void buildAccomodation() override;
};


class AdventureTourBuilder : public TravelBuilder {
    public:
    void buildFlight()       override;
    void buildMealPlan()     override;
    void buildTransfer()     override;
    void buildExcursions()   override;
    void buildAccomodation() override;
};

class SightseeingTourBuilder : public TravelBuilder {
    public:
    void buildFlight()       override;
    void buildMealPlan()     override;
    void buildTransfer()     override;
    void buildExcursions()   override;
    void buildAccomodation() override;
};


#endif //BUILDERS_H