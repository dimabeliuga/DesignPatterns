#ifndef CONVEYORLINE_H
#define CONVEYORLINE_H

///* Here can more complex classes be included, but for this example it is not necessary

#include <string>

class ConveyorLine
{
    private:
        bool isLaunched;
        std::string currentModelCreation;
        size_t speed;
    public:
        ConveyorLine();
        void launch();
        void stop();
        void setSpeed(int speed);
        void setModelWillBeCreated(std::string model);
        void printStatus();
        bool getIsLaunched();
        std::string getCurrentModelCreation();
        int getSpeed();
        ~ConveyorLine();
};

#endif // CONVEYORLINE_H