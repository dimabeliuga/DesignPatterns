#ifndef HEATING_H
#define HEATING_H

#include <random>
#include <iostream>

class Heating {
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
            std::cout << "Heating is turned on" << std::endl;
        }
        void turnOff() {
            isOn = false;
            std::cout << "Heating is turned off" << std::endl;
        }
        void setTemperature(uint16_t temperature) {
            this->temperature = temperature;
            std::cout << "Heating temperature is set to " << temperature << std::endl;
            std::cout << "Current temperature is " << Thermometer() << std::endl;
        }
        void printStatus() const {
            std::cout << "Heating is " << (isOn ? "on" : "off") << std::endl;
            std::cout << "Heating temperature is " << (int)temperature << std::endl;
        }
        bool getTemperature() const {
            return temperature;
        }

};

#endif // HEATING_H