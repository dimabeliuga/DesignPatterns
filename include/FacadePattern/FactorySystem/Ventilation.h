#ifndef VENTILATION_H
#define VENTILATION_H

#include <string>

class Ventilation {
    public:
        Ventilation();
        void turnOnVentilation();
        void turnOffVentilation();
        void setVentilationSpeed(int speed);
};

#endif // VENTILATION_H