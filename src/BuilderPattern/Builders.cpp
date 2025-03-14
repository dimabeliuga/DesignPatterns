#include "Builders.h"

//* BeachVacationBuilder
void BeachVacationBuilder::buildExcursions() {
    travel.excursions = "Not included";
}
void  BeachVacationBuilder::buildAccomodation() {
    travel.accomodationType = 4;
}
void BeachVacationBuilder::buildFlight() {
    travel.flightType = "econom";
}
void BeachVacationBuilder::buildMealPlan() {
    travel.mealPlan = "bed and breakfast";
}
void BeachVacationBuilder::buildTransfer() {
    travel.transferType = "bus(couch)";
}

//*AdventureTourBuilder
void AdventureTourBuilder::buildExcursions() {
    travel.excursions = "Hiking in the mountains/Rafting";
}
void AdventureTourBuilder::buildAccomodation() {
    travel.accomodationType = 5;
}
void AdventureTourBuilder::buildFlight() {
    travel.flightType = "business";
}
void AdventureTourBuilder::buildMealPlan() {
    travel.mealPlan = "all inclusive";
}
void AdventureTourBuilder::buildTransfer() {
    travel.transferType = "car";
}

//* SightseeingTourBuilder
void SightseeingTourBuilder::buildExcursions() {
    travel.excursions = "Sightseeing tour/History museums";
}
void SightseeingTourBuilder::buildAccomodation() {
    travel.accomodationType = 3;
}
void SightseeingTourBuilder::buildFlight() {
    travel.flightType = "econome";
}
void SightseeingTourBuilder::buildMealPlan() {
    travel.mealPlan = "only breakfast";
}
void SightseeingTourBuilder::buildTransfer() {
    travel.transferType = "plaine";
}
