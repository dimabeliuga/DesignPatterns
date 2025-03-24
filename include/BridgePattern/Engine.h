#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>

enum class ENGINE_TYPE { PETROL, HYBRID, ELECTRIC};

class Engine {
protected:
    ENGINE_TYPE engineType;
    size_t horsePower;
    size_t yearProduction;
    bool isStarted = false;

public:
    Engine() = default;
    Engine(ENGINE_TYPE _engineType, size_t _horsePower, size_t _yearProduction)
        : engineType(_engineType), horsePower(_horsePower), yearProduction(_yearProduction) {}

    virtual bool startEngine() = 0;
    virtual void isEngineRunning() = 0;
    virtual void turnOffEngine() = 0;
    virtual void showDescription() const = 0;
    virtual ~Engine() = default;
};

//* Petrol Engine
class PetrolEngine : public Engine {
public:
    PetrolEngine(size_t _horsePower, size_t _yearProduction)
        : Engine(ENGINE_TYPE::PETROL, _horsePower, _yearProduction) {}

    bool startEngine() override;
    void isEngineRunning() override;
    void turnOffEngine() override;
    void showDescription() const override;
};

//* Electrical Engine
class ElectricEngine : public Engine {
public:
    ElectricEngine(size_t _horsePower, size_t _yearProduction)
        : Engine(ENGINE_TYPE::ELECTRIC, _horsePower, _yearProduction) {}

    bool startEngine() override;
    void isEngineRunning() override;
    void turnOffEngine() override;
    void showDescription() const override;
};

//* HybridEngine
class HybridEngine : public Engine {
public:
    HybridEngine(size_t _horsePower, size_t _yearProduction)
        : Engine(ENGINE_TYPE::HYBRID, _horsePower, _yearProduction) {}

    bool startEngine() override;
    void isEngineRunning() override;
    void turnOffEngine() override;
    void showDescription() const override;
};

#endif // ENGINE_H