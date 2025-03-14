#ifndef TRAVEL_H
#define TRAVEL_H

#include <string>
#include <iostream> 

struct Travel{
    size_t accomodationType;
    std::string excursions;
    std::string mealPlan;
    std::string flightType;
    std::string transferType;

    void type() const {
        std::cout << "-----------------------" << std::endl
                  << "Your tour information:" << std::endl
                  << "Flight type: " << flightType << std::endl
                  << "Meal plan: " << mealPlan << std::endl
                  << "Transfer: " << transferType << std::endl
                  << "Excursions: " << excursions << std::endl
                  << "Accomodation: " << accomodationType << std::endl;
    }
};

#endif //TRAVEL_H