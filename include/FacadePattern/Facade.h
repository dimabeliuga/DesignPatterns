#ifndef FACEDE_H
#define FACEDE_H

#include "FactorySystem/ConveyorLine.h"
#include "FactorySystem/Lighting.h"
#include "FactorySystem/QualityControlSystem.h"
#include "FactorySystem/RoboticManipulator.h"
#include "FactorySystem/Ventilation.h"
#include "FactorySystem/Warehouse.h"

struct FactorySystemFacade
{
    Lighting lighting;
    Warehouse warehouse;
    Ventilation ventilation;
    ConveyorLine conveyorLine;
    RoboticManipulator roboticManipulator;
    QualityControlSystem qualityControlSystem;
};

class FactoryControlPanel {
    private:
        FactorySystemFacade factorySystemFacade;
    public:
        void stopProduction();
        void prepareWorkShop();
        void emergencyShutdown();
        void changeProductionModel(std::string model);
        void launchProduction(std::string model, int speed, std::string operation);
};
#endif // FACEDE_H


/* example of usage
    FactoryControlPanel factoryControlPanel;

    std::cout << "\n\nLaunch production" << std::endl;
    factoryControlPanel.launchProduction( "model", 10, "operation");
    
    std::cout << "\n\nPrepare work shop" << std::endl;
    factoryControlPanel.prepareWorkShop();

    std::cout << "\n\nStop production" << std::endl;
    factoryControlPanel.stopProduction();
    
    std::cout << "\n\nChange production model" << std::endl;
    factoryControlPanel.changeProductionModel("new model");
    
    std::cout << "\n\nEmergency shutdown" << std::endl;
    factoryControlPanel.emergencyShutdown();

*/