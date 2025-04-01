#ifndef CALL_CENTER_H
#define CALL_CENTER_H

#include "Support.h"
#include <iostream>

/// @brief CallCenter class is the first line of support
/// @details CallCenter class is the first line of support. It inherits from the Support class. It can solve requests that are in the SOFTWARE category and have a LOW difficulty level. If it cannot solve the request, it will pass it to the next line of support.

class CallCenter : public Support {
    public:
        CallCenter() = default;
        ~CallCenter() override = default;

        /// @brief handleRequest checks wherther the request can be solved by the callCenter or not. If it can, it will solve the request. If it cannot, it will pass the request to the next line of support.
        bool handleRequest(std::shared_ptr<Request> request) override {
            if (request->getCategory() == REQUEST_CATEGORY::SOFTWARE && request->getDifficultyLevel() == DIFFICULTY_LEVEL::LOW) {
                std::cout << "First Line of Support: I can solve this request" << std::endl;
                return true;
            } else {
                std::cout << "First Line of Support: I cannot solve this request" << std::endl;
                if (nextSupport != nullptr) {
                    nextSupport->handleRequest(request);
                }
                return false;
            }
        }

};


#endif //CALL_CENTER_H