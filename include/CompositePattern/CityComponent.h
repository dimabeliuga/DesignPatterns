#ifndef CITY_COMPONENT_H
#define CITY_COMPONENT_H

#include <string>

class CityComponent {
    public:
        virtual double getTotalArea() const = 0;
        virtual double calculateEnergy() const = 0;
        virtual void printStructure() const = 0;
        virtual void optimizeEnergy(size_t percentage) = 0;
        virtual void checkEnergyOverUse(size_t limit) const = 0;
        virtual std::string getAddress() const = 0;

        virtual ~CityComponent() = default;
};

#endif //CITY_COMPONENT_H


/* example of usage
    Region region("North Region");

    auto city = std::make_unique<City>("Metropolis");
    city->addComponent(std::make_unique<MultiStoreyBuilding>("123 Main St", 5, 20, 1000.0, 500.0));
    city->addComponent(std::make_unique<ShoppingCenter>("456 Market St", 3, 50, 2000.0, 1000.0));

    auto village = std::make_unique<Village>("Smallville");
    village->addComponent(std::make_unique<Farm>("101 Rural Rd", 5, 10000.0, 500.0));

    region.addComponent(std::move(city));
    region.addComponent(std::move(village));
    region.addComponent(std::make_unique<Factory>("789 Industrial Ave", 10, 5000.0, 2000.0));

    std::cout << "Region structure:\n";
    region.printStructure();

    std::cout << "\nTotal area: " << region.getTotalArea() << " м2\n";
    std::cout << "Total energy: " << region.calculateEnergy() << " kW h\n";

    std::cout << "\nRemoving Metropolis:\n";
    region.removeComponent("Metropolis");

    std::cout << "\nUpdated structure:\n";
    region.printStructure();

*/