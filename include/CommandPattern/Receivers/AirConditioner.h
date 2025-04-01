#ifndef AIR_CONDITIONER_H
#define AIR_CONDITIONER_H

#include <random>
#include <iostream>

class AirConditioner {
    private:
        bool isOn = false;
        uint16_t temperature = 0;

        uint16_t Thermometer() const {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(15, 30); // Random temperature between 15 and 30 degrees
            return dis(gen);
        }
    public:
        void turnOn() {
            isOn = true;
            std::cout << "Air conditioner is turned on" << std::endl;
        }
        void turnOff() {
            isOn = false;
            std::cout << "Air conditioner is turned off" << std::endl;
        }
        void setTemperature(uint16_t temperature) {
            this->temperature = temperature;
            std::cout << "Air conditioner temperature is set to " << temperature << std::endl;
            std::cout << "Current temperature is " << Thermometer() << std::endl;
        }
        void getStatus() const {
            std::cout << "Air conditioner is " << (isOn ? "on" : "off") << std::endl;
            std::cout << "Air conditioner temperature is " << (int)temperature << std::endl;
        }
        uint16_t getTemperature() const { return temperature; }
};

#endif // AIR_CONDITIONER_H