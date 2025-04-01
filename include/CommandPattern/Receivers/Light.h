#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

class Light {
    private:
        bool isOn = false;
        uint16_t brightness = 0;
    public:
        void turnOn() {
            isOn = true;
            std::cout << "Light is turned on" << std::endl;
        }
        void tunrnOff() {
            isOn = false;
            std::cout << "Light is turned off" << std::endl;
        }
        void setBrightness(uint16_t brightness) {
            this->brightness = brightness;
            std::cout << "Light brightness is set to " << (int)brightness << std::endl;
        }
        void printStatus() const {
            std::cout << "Light is " << (isOn ? "on" : "off") << std::endl;
            std::cout << "Light brightness is " << (int)brightness << std::endl;
        }
        bool getStatus() const {
            return isOn;
        }
};

#endif // LIGHT_H