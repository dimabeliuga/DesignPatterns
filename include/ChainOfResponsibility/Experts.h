#ifndef EXPERTS_H
#define EXPERTS_H

#include "Support.h"
#include <random>
#include <iostream>

/// @brief Experts class is the third line of support
/// @details Experts class is the third line of support. It inherits from the Support class. It can solve requests that are in the OTHER category. If it cannot solve the request, it will pass the request to the next line of support.
class Experts : public Support {
    public:
        Experts() = default;
        ~Experts() override = default;

        bool handleRequest(std::shared_ptr<Request> request) override {
            if (request->getCategory() != REQUEST_CATEGORY::OTHER) {
                std::cout << "Third Line of Support: I can solve this request" << std::endl;
                return true;
            } else {
                std::cout << "Third Line of Support: I cannot solve this request" << std::endl;
                if (nextSupport != nullptr) {
                    nextSupport->handleRequest(request);
                }
                return false;
            }
        }
};
#endif // EXPERTS_H