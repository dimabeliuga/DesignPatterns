#ifndef CHAIN_BUILDER_H
#define CHAIN_BUILDER_H

#include "SupportDepartments.h"
#include <memory>

/// @brief ChainBuilder class is used to build the chain of support departments
/// @details ChainBuilder class is used to build the chain of support departments. It creates the chain of support departments and sets the next department for each department. It also provides a method to send a request to the first line of support.
class ChainBuilder{
    private:
        std::shared_ptr<Support> callCenter;
        std::shared_ptr<Support> middleLevelSpecialist;
        std::shared_ptr<Support> experts;
        std::shared_ptr<Support> producer;
        
    public:
        ChainBuilder() {
            /// all departments are created and linked together
            callCenter = std::make_shared<CallCenter>();
            middleLevelSpecialist = std::make_shared<MiddleLevelSpecialist>();
            experts = std::make_shared<Experts>();
            producer = std::make_shared<Producer>();

            callCenter->setNextSupport(middleLevelSpecialist);
            middleLevelSpecialist->setNextSupport(experts);
            experts->setNextSupport(producer);
        }

        std::shared_ptr<Support> getSupportChain() {
            return callCenter;
        }
        
        void sendRequest(std::shared_ptr<Request> request) {
            callCenter->handleRequest(request);
        }
};

#endif //CHAIN_BUILDER_H

/*
    ChainBuilder chainBuilder;
    std::shared_ptr<Request> request = std::make_shared<Request>(
        "I need help with my software", 
        REQUEST_CATEGORY::SOFTWARE, 
        DIFFICULTY_LEVEL::LOW, 
        12345, 
        false
    );
    std::cout << "\n\n Request id: " << request->getRequestId() << std::endl;
    
    chainBuilder.sendRequest(request);
    request = std::make_shared<Request>(
        "I need help with my hardware", 
        REQUEST_CATEGORY::HARDWARE, 
        DIFFICULTY_LEVEL::MEDIUM, 
        12345, 
        false
    );
    std::cout << "\n\n Request id: " << request->getRequestId() << std::endl;
    
    chainBuilder.sendRequest(request);
    request = std::make_shared<Request>(
        "I need help with my networking", 
        REQUEST_CATEGORY::NETWORKING, 
        DIFFICULTY_LEVEL::HIGH, 
        12345, 
        false
    );
    std::cout << "\n\n Request id: " << request->getRequestId() << std::endl;
    
    chainBuilder.sendRequest(request);
    request = std::make_shared<Request>(
        "I need help with my security", 
        REQUEST_CATEGORY::SECURITY, 
        DIFFICULTY_LEVEL::LOW, 
        12345, 
        false
    );
    std::cout << "\n\n Request id: " << request->getRequestId() << std::endl;
    
    chainBuilder.sendRequest(request);
    request = std::make_shared<Request>(
        "I need help with my other", 
        REQUEST_CATEGORY::OTHER, 
        DIFFICULTY_LEVEL::MEDIUM, 
        12345, 
        false
    );
    std::cout << "\n\nRequest id: " << request->getRequestId() << std::endl;
    
    chainBuilder.sendRequest(request);
*/