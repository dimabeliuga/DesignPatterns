#ifndef MIDDLE_LEVEL_SPECIALIST_H
#define MIDDLE_LEVEL_SPECIALIST_H

#include "Support.h"
#include <iostream>

/// @brief MiddleLevelSpecialist class is the second line of support

class MiddleLevelSpecialist : public Support {
    public:
        MiddleLevelSpecialist() = default;
        ~MiddleLevelSpecialist() override = default;

        bool handleRequest(std::shared_ptr<Request> request) override {
            auto category = request->getCategory();
            if ((category != REQUEST_CATEGORY::OTHER && category != REQUEST_CATEGORY::SECURITY) && request->getDifficultyLevel() <= DIFFICULTY_LEVEL::MEDIUM) {
                std::cout << "Second Line of Support: I can solve this request" << std::endl;
                return true;
            } else {
                std::cout << "Second Line of Support: I cannot solve this request" << std::endl;
                if (nextSupport != nullptr) {
                    nextSupport->handleRequest(request);
                }
                return false;
            }
        }
};

#endif //MIDDLE_LEVEL_SPECIALIST_H