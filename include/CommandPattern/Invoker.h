#ifndef INVOKER_H
#define INVOKER_H

#include "ConcreteCommands.h"
#include <stack>
#include <memory>


class SmartHomeController {
    private: 
        std::stack<std::shared_ptr<Command>> history;
        size_t MAX_HISTORY_CAPACITY = 5;
    public:
        SmartHomeController() = default;
        
        bool addCommand(std::shared_ptr<Command> command) {
            if(command != nullptr){
                if(history.size() >= MAX_HISTORY_CAPACITY){
                    history.pop();
                }
                history.emplace(command);
                std::cout << "Command has been added to history" << std::endl;
                return true;
            }
            return false;
        }
        void execute(std::shared_ptr<Command> command) {
            if(addCommand(command)) {
                command -> execute();
            } else {
                std::cout << "Something went wrong when trying to use your command" << std::endl;
            }
        }
        void getName(std::shared_ptr<Command> command) {
            if(command != nullptr) {
                command -> getName();
            }
        }
        void undo() {
            history.top() -> undo();
            history.pop();
        }
};

#endif //INVOKER_H

/* example of usage
void testSmartHomeController() {
    std::cout << "\n=== Testing SmartHomeController ===\n" << std::endl;

    // Create test devices
    auto light = std::make_shared<Light>();
    auto audio = std::make_shared<AudioSystem>();

    // Create controller
    SmartHomeController controller;

    // Test 1
    std::cout << "Test 1: Adding valid command" << std::endl;
    auto lightCommand = std::make_shared<TurnOnLight>(light);
    bool result = controller.addCommand(lightCommand);
    assert(result == true);
    std::cout << "✓ Valid command added successfully\n" << std::endl;

    // Test 2
    std::cout << "Test 2: Adding nullptr command" << std::endl;
    result = controller.addCommand(nullptr);
    assert(result == false);
    std::cout << "✓ Nullptr command rejected successfully\n" << std::endl;

    // Test 3
    std::cout << "Test 3: Command execution" << std::endl;
    auto musicCommand = std::make_shared<TurnOnTheMusic>(audio);
    controller.execute(musicCommand);
    std::cout << "✓ Command executed successfully\n" << std::endl;

    // Test 4
    std::cout << "Test 4: Testing history capacity limit" << std::endl;
    for(int i = 0; i < 6; i++) { // Adding more commands than MAX_HISTORY_CAPACITY
        controller.execute(std::make_shared<TurnOnLight>(light));
    }
    std::cout << "✓ History capacity test completed\n" << std::endl;

    // Test 5
    std::cout << "Test 5: Testing undo functionality" << std::endl;
    controller.execute(lightCommand);
    std::cout << "Before undo:" << std::endl;
    light->printStatus();
    
    controller.undo();
    std::cout << "\nAfter undo:" << std::endl;
    light->printStatus();
    std::cout << "✓ Undo functionality test completed\n" << std::endl;

    // Test 6: 
    std::cout << "Test 6: Testing getName functionality" << std::endl;
    std::cout << "Command name: ";
    controller.getName(lightCommand);
    std::cout << "✓ getName test completed\n" << std::endl;
}
*/