#include "Ventilation.h"

#include <iostream>

Ventilation::Ventilation()
{
    std::cout << "Ventilation is created." << std::endl;
}

void Ventilation::turnOnVentilation()
{
    std::cout << "Ventilation is turned on." << std::endl;
}

void Ventilation::turnOffVentilation()
{
    std::cout << "Ventilation is turned off." << std::endl;
}

void Ventilation::setVentilationSpeed(int speed)
{
    std::cout << "Ventilation speed is set to " << speed << "." << std::endl;
}
