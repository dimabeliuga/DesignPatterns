#include "Vehicle.h"

//* Vehicle
void Vehicle::showInfo() const
{
    std::cout << "Vehicle: " << brand << " " << model 
    << ", Color: " << color << "\n";
    engine->showDescription();
}

void Vehicle::checkEngineStatus() const
{
    engine->isEngineRunning();
}

//* Car
void Car::startVehicle() {
    std::cout << "Car is preparing to move...\n";
    checkEngineStatus();
    std::cout << "Starting the car: ";
    if (engine->startEngine()) {
        std::cout << "Car is now moving on the road.\n";
    }
}

void Car::turnOffVehicle() {
    std::cout << "Stopping the car...\n";
    engine->turnOffEngine();
    std::cout << "Car is now parked.\n";
}

//* Bicycle
void Bicycle::startVehicle() {
    std::cout << "Bicycle is ready to ride...\n";
    checkEngineStatus();
    std::cout << "Starting the bicycle: ";
    if (engine->startEngine()) {
        std::cout << "Bicycle is now pedaling on the bike path.\n";
    }
}

void Bicycle::turnOffVehicle() {
    std::cout << "Stopping the bicycle...\n";
    engine->turnOffEngine();
    std::cout << "Bicycle is now stationary.\n";
}

//* Boat
void Boat::startVehicle() {
    std::cout << "Boat is preparing to sail...\n";
    checkEngineStatus();
    std::cout << "Starting the boat: ";
    if (engine->startEngine()) {
        std::cout << "Boat is now sailing on the water.\n";
    }
}

void Boat::turnOffVehicle() {
    std::cout << "Docking the boat...\n";
    engine->turnOffEngine();
    std::cout << "Boat is now at the dock.\n";
}