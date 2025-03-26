#ifndef LIGHTING_H
#define LIGHTING_H

#include <string>

class Lighting {
    public:
        Lighting();
        void turnOnLighting(std::string area);
        void turnOffLighting(std::string area);
        void setLightingIntensity(std::string area, int intensity);
};

#endif // LIGHTING_H