#ifndef VEHICLE_H
#define VEHICLE_H

#include "Engine.h"
#include <memory>
#include <string>

class Vehicle {
    protected:
        std::unique_ptr<Engine> engine;
        std::string color;
        std::string brand;
        std::string model;

    public:
        Vehicle(std::unique_ptr<Engine> _engine, std::string_view _color,
                std::string_view _brand, std::string_view _model)
            : engine(std::move(_engine)), color(_color),
            brand(_brand), model(_model) {}

        virtual void startVehicle() = 0;
        virtual void turnOffVehicle() = 0;

        void showInfo() const;
        void checkEngineStatus() const;

        virtual ~Vehicle() = default;
};

//* Car 
class Car : public Vehicle {
public:
    Car(std::unique_ptr<Engine> _engine, std::string_view _color,
        std::string_view _brand, std::string_view _model)
        : Vehicle(std::move(_engine), _color, _brand, _model) {}

    void startVehicle() override;
    void turnOffVehicle() override;
};

//* Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(std::unique_ptr<Engine> _engine, std::string_view _color,
            std::string_view _brand, std::string_view _model)
        : Vehicle(std::move(_engine), _color, _brand, _model) {}

    void startVehicle() override;
    void turnOffVehicle() override;
};

//* Boat
class Boat : public Vehicle {
public:
    Boat(std::unique_ptr<Engine> _engine, std::string_view _color,
         std::string_view _brand, std::string_view _model)
        : Vehicle(std::move(_engine), _color, _brand, _model) {}

    void startVehicle() override;
    void turnOffVehicle() override;
};

#endif // VEHICLE_H


/* example
    auto petrolEngine = std::make_unique<PetrolEngine>(150, 2018);
    auto electricEngine = std::make_unique<ElectricEngine>(120, 2020);
    auto hybridEngine = std::make_unique<HybridEngine>(180, 2022);

    Car car(std::move(petrolEngine), "Red", "Toyota", "Camry");
    Bicycle bicycle(std::move(electricEngine), "Blue", "Giant", "Escape");
    Boat boat(std::move(hybridEngine), "White", "Yamaha", "242X");

    std::cout << "---Testing Car---\n";
    car.showInfo();
    car.startVehicle();
    car.checkEngineStatus();
    car.turnOffVehicle();
    std::cout << "\n";

    std::cout << "---Testing Bicycle---n";
    bicycle.showInfo();
    bicycle.startVehicle();
    bicycle.checkEngineStatus();
    bicycle.turnOffVehicle();
    std::cout << "\n";

    std::cout << "---Testing Boat---n";
    boat.showInfo();
    boat.startVehicle();
    boat.checkEngineStatus();
    boat.turnOffVehicle();
*/