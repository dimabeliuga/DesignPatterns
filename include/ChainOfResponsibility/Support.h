#ifndef SUPPORT_H
#define SUPPORT_H

#include <memory>
#include "Request.h"

/// @brief Support class is the base abstract class for all support classes

class Support {
    protected:
        std::shared_ptr<Support> nextSupport;
    public:
    Support() = default;
        virtual ~Support() = default;
        
        virtual bool setNextSupport(std::shared_ptr<Support> next) {
            if (nextSupport == nullptr) {
                nextSupport = next;
                return true;
            }
            return false;
        }
        virtual bool handleRequest(std::shared_ptr<Request> request) = 0;
};

#endif // SUPPORT_H