#ifndef ROBOTICMANIPULATORS_H
#define ROBOTICMANIPULATORS_H

#include <string>

//* Here can more complex classes be included, but for this example it is not necessary

class RoboticManipulator {
    private:
        bool isLaunched;
        std::string currentOperation;
    public:
        RoboticManipulator();
        void launch();
        void stop();
        void setOperation(std::string operation);
        void printStatus();
        bool getIsLaunched();
        void calibrate();
        std::string getCurrentOperation();

        ~RoboticManipulator();
};

#endif // ROBOTICMANIPULATORS_H