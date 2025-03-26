#include "ConveyorLine.h"
#include <iostream>

ConveyorLine::ConveyorLine()
{
    std::cout << "Conveyor line is created." << std::endl;
    isLaunched = false;
    currentModelCreation = "";
    speed = 0;
}

void ConveyorLine::launch()
{
    std::cout << "Conveyor line is launched." << std::endl;
    isLaunched = true;
}

void ConveyorLine::stop()
{
    std::cout << "Conveyor line is stopped." << std::endl;
    isLaunched = false;
}

void ConveyorLine::setSpeed(int speed)
{
    this->speed = speed;
    std::cout << "Conveyor line speed is set to " << speed << "." << std::endl;
}

void ConveyorLine::setModelWillBeCreated(std::string model)
{
    currentModelCreation = model;
    std::cout << "Model " << model << " is being created." << std::endl;
}

void ConveyorLine::printStatus()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "Conveyor line is launched: " << isLaunched << std::endl;
    std::cout << "Current model creation: " << currentModelCreation << std::endl;
    std::cout << "Conveyor line speed: " << speed << std::endl;
    std::cout << "-----------------------" << std::endl;
}

bool ConveyorLine::getIsLaunched()
{
    return isLaunched;
}

std::string ConveyorLine::getCurrentModelCreation()
{
    return currentModelCreation;
}

int ConveyorLine::getSpeed()
{
    return speed;
}

ConveyorLine::~ConveyorLine()
{
    std::cout << "Conveyor line is destroyed." << std::endl;
}	