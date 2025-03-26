#include "RoboticManipulator.h"
#include <iostream>

RoboticManipulator::RoboticManipulator()
{
    std::cout << "Robotic manipulator is created." << std::endl;
    isLaunched = false;
    currentOperation = "";
}

void RoboticManipulator::launch()
{
    std::cout << "Robotic manipulator is launched." << std::endl;
    isLaunched = true;
}

void RoboticManipulator::stop()
{
    std::cout << "Robotic manipulator is stopped." << std::endl;
    isLaunched = false;
}

void RoboticManipulator::setOperation(std::string operation)
{
    currentOperation = operation;
    std::cout << "Operation " << operation << " is set." << std::endl;
}

void RoboticManipulator::printStatus()
{
    std::cout << "-----------------------" << std::endl;
    std::cout << "Robotic manipulator is launched: " << isLaunched << std::endl;
    std::cout << "Current operation: " << currentOperation << std::endl;
    std::cout << "-----------------------" << std::endl;
}

bool RoboticManipulator::getIsLaunched()
{
    return isLaunched;
}

void RoboticManipulator::calibrate()
{
    std::cout << "Robotic manipulator is calibrated." << std::endl;
}

std::string RoboticManipulator::getCurrentOperation()
{
    return currentOperation;
}

RoboticManipulator::~RoboticManipulator()
{
    std::cout << "Robotic manipulator is destroyed." << std::endl;
}
