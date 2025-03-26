#include "QualityControlSystem.h"

#include <iostream>

QualityControlSystem::QualityControlSystem()
{
    std::cout << "Quality control system is created." << std::endl;
    isLaunched = false;
}

void QualityControlSystem::turnOnQualityControlSystem()
{
    std::cout << "Quality control system is turned on." << std::endl;
    isLaunched = true;
}

void QualityControlSystem::turnOffQualityControlSystem()
{
    std::cout << "Quality control system is turned off." << std::endl;
    isLaunched = false;
}

void QualityControlSystem::checkItemQuality(std::string item)
{
    std::cout << "Item " << item << " is checked." << std::endl;
}

void QualityControlSystem::sentReport()
{
    std::cout << "Quality control report is sent." << std::endl;
}
