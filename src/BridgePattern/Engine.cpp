#include "Engine.h"

//* Petrol Engine
bool PetrolEngine::startEngine() {
    if (!isStarted) {
        std::cout << "Petrol engine starting: Vroom-vroom!\n";
        isStarted = true;
        return true;
    }
    std::cout << "Petrol engine is already running.\n";
    return false;
}

void PetrolEngine::isEngineRunning() {
    if (isStarted) {
        std::cout << "Petrol engine is running: rattling and smoking.\n";
    } else {
        std::cout << "Petrol engine is off.\n";
    }
}

void PetrolEngine::turnOffEngine() {
    if (isStarted) {
        std::cout << "Petrol engine shutting down: silence.\n";
        isStarted = false;
    } else {
        std::cout << "Petrol engine is already off.\n";
    }
}

void PetrolEngine::showDescription() const {
    std::cout << "Petrol engine: " << horsePower << " hp, manufactured in " << yearProduction << ".\n";
}

//* Electrical Engine
bool ElectricEngine::startEngine() {
    if (!isStarted) {
        std::cout << "Electric engine starting: Quiet hum.\n";
        isStarted = true;
        return true;
    }
    std::cout << "Electric engine is already running.\n";
    return false;
}

void ElectricEngine::isEngineRunning() {
    if (isStarted) {
        std::cout << "Electric engine is running: silent and eco-friendly.\n";
    } else {
        std::cout << "Electric engine is off.\n";
    }
}

void ElectricEngine::turnOffEngine() {
    if (isStarted) {
        std::cout << "Electric engine shutting down: complete silence.\n";
        isStarted = false;
    } else {
        std::cout << "Electric engine is already off.\n";
    }
}

void ElectricEngine::showDescription() const {
    std::cout << "Electric engine: " << horsePower << " hp, manufactured in " << yearProduction << ".\n";
}

//* Hybrid Engine
bool HybridEngine::startEngine() {
    if (!isStarted) {
        std::cout << "Hybrid engine starting: Hum first, then petrol.\n";
        isStarted = true;
        return true;
    }
    std::cout << "Hybrid engine is already running.\n";
    return false;
}

void HybridEngine::isEngineRunning() {
    if (isStarted) {
        std::cout << "Hybrid engine is running: switching between electric and petrol.\n";
    } else {
        std::cout << "Hybrid engine is off.\n";
    }
}

void HybridEngine::turnOffEngine() {
    if (isStarted) {
        std::cout << "Hybrid engine shutting down: both modes stop.\n";
        isStarted = false;
    } else {
        std::cout << "Hybrid engine is already off.\n";
    }
}

void HybridEngine::showDescription() const {
    std::cout << "Hybrid engine: " << horsePower << " hp, manufactured in " << yearProduction << ".\n";
}