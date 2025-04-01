#ifndef PRODUCER_H
#define PRODUCER_H

#include "Support.h"
#include <iostream>

/// @brief  Producer class is the last line of support. It always helps the user
class Producer : public Support {
    public:
        Producer() = default;
        ~Producer() override = default;

        bool handleRequest(std::shared_ptr<Request> request) override {
            std::cout << "Producer: I can solve this request" << std::endl;
            return true;
        }
};

#endif //PRODUCER_H