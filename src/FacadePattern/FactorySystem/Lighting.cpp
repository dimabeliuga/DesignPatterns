#include "Lighting.h"

#include <iostream>

Lighting::Lighting()
{
    std::cout << "Lighting is created." << std::endl;
}

void Lighting::turnOnLighting(std::string area)
{
    std::cout << "Lighting in " << area << " is turned on." << std::endl;
}

void Lighting::turnOffLighting(std::string area)
{
    std::cout << "Lighting in " << area << " is turned off." << std::endl;
}

void Lighting::setLightingIntensity(std::string area, int intensity)
{
    std::cout << "Lighting intensity in " << area << " is set to " << intensity << "." << std::endl;
}

