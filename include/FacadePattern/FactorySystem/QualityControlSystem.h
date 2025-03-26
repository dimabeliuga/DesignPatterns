#ifndef QUALITYCONTROLSYSTEM_H
#define QUALITYCONTROLSYSTEM_H

#include <string>

class QualityControlSystem {
    private:
        bool isLaunched;
    public:
        QualityControlSystem();
        void turnOnQualityControlSystem();
        void turnOffQualityControlSystem();
        void checkItemQuality(std::string item);
        void sentReport();
};


#endif // QUALITYCONTROLSYSTEM_H