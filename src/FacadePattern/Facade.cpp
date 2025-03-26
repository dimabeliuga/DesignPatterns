#include "Facade.h"

void FactoryControlPanel::stopProduction()
{
    factorySystemFacade.conveyorLine.stop();
    factorySystemFacade.roboticManipulator.stop();
    factorySystemFacade.qualityControlSystem.turnOffQualityControlSystem();
    factorySystemFacade.ventilation.turnOffVentilation();
    factorySystemFacade.lighting.turnOffLighting("workshop");
}

void FactoryControlPanel::prepareWorkShop()
{
    factorySystemFacade.warehouse.checkSavings("model");
    factorySystemFacade.warehouse.orderItem("model", 10);
    factorySystemFacade.warehouse.deliverOnConveyorLine("model", 10);
    factorySystemFacade.conveyorLine.setSpeed(10);
    factorySystemFacade.conveyorLine.setModelWillBeCreated("model");
    factorySystemFacade.roboticManipulator.setOperation("operation");
    factorySystemFacade.roboticManipulator.calibrate();
    factorySystemFacade.qualityControlSystem.turnOnQualityControlSystem();
    factorySystemFacade.ventilation.setVentilationSpeed(10);
    factorySystemFacade.lighting.setLightingIntensity("workshop", 10);
    factorySystemFacade.lighting.turnOnLighting("workshop");
    factorySystemFacade.conveyorLine.launch();
    factorySystemFacade.roboticManipulator.launch();
}

void FactoryControlPanel::emergencyShutdown()
{
    factorySystemFacade.conveyorLine.stop();
    factorySystemFacade.roboticManipulator.stop();
    factorySystemFacade.qualityControlSystem.turnOffQualityControlSystem();
    factorySystemFacade.ventilation.turnOffVentilation();
    factorySystemFacade.lighting.turnOffLighting("workshop");
}

void FactoryControlPanel::changeProductionModel(std::string model)
{
    factorySystemFacade.conveyorLine.stop();
    factorySystemFacade.roboticManipulator.stop();
    factorySystemFacade.qualityControlSystem.turnOffQualityControlSystem();
    factorySystemFacade.ventilation.turnOffVentilation();
    factorySystemFacade.lighting.turnOffLighting("workshop");

    factorySystemFacade.warehouse.checkSavings(model);
    factorySystemFacade.warehouse.orderItem(model, 10);
    factorySystemFacade.warehouse.deliverOnConveyorLine(model, 10);
    factorySystemFacade.conveyorLine.setSpeed(10);
    factorySystemFacade.conveyorLine.setModelWillBeCreated(model);
    factorySystemFacade.roboticManipulator.setOperation("operation");
    factorySystemFacade.roboticManipulator.calibrate();
    factorySystemFacade.qualityControlSystem.turnOnQualityControlSystem();
    factorySystemFacade.ventilation.setVentilationSpeed(10);
    factorySystemFacade.lighting.setLightingIntensity("workshop", 10);
    factorySystemFacade.lighting.turnOnLighting("workshop");
    factorySystemFacade.conveyorLine.launch();
    factorySystemFacade.roboticManipulator.launch();
}

void FactoryControlPanel::launchProduction(std::string model, int speed, std::string operation)
{
    factorySystemFacade.conveyorLine.stop();
    factorySystemFacade.roboticManipulator.stop();
    factorySystemFacade.qualityControlSystem.turnOffQualityControlSystem();
    factorySystemFacade.ventilation.turnOffVentilation();
    factorySystemFacade.lighting.turnOffLighting("workshop");

    factorySystemFacade.warehouse.checkSavings(model);
    factorySystemFacade.warehouse.orderItem(model, 10);
    factorySystemFacade.warehouse.deliverOnConveyorLine(model, 10);
    factorySystemFacade.conveyorLine.setSpeed(speed);
    factorySystemFacade.conveyorLine.setModelWillBeCreated(model);
    factorySystemFacade.roboticManipulator.setOperation(operation);
    factorySystemFacade.roboticManipulator.calibrate();
    factorySystemFacade.qualityControlSystem.turnOnQualityControlSystem();
    factorySystemFacade.ventilation.setVentilationSpeed(10);
    factorySystemFacade.lighting.setLightingIntensity("workshop", 10);
    factorySystemFacade.lighting.turnOnLighting("workshop");
    factorySystemFacade.conveyorLine.launch();
    factorySystemFacade.roboticManipulator.launch();
}
