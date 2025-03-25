#ifndef BUILDING_H
#define BUILDING_H

#include <CityComponent.h>
#include <iostream>

enum class BUILDING_TYPE {RESIDENTIAL, PUBLIC, INDUSTRIAL, AGRICULTURAL};

class Building : public CityComponent{
    protected:
        BUILDING_TYPE type;
        std::string adress;
        double squareMeters;
        double energyConsuming;

        std::string_view buildingTypeToString() const;
    public:
        //* Constructor
        Building(BUILDING_TYPE _type, std::string_view _adress, double _squareMeters, double _energyConsuming);

        //* Deleted constuctors
        Building(const Building&) = delete;
        Building(Building&&) noexcept = delete;
        Building& operator=(const Building&) = delete;
        Building& operator=(Building&&) noexcept = delete;

        //* Override functions
        double getTotalArea() const override;
        double calculateEnergy() const  override;
        void printStructure() const override;
        void optimizeEnergy(size_t percentege) override;
        void checkEnergyOverUse(size_t limit) const override;
        std::string getAddress() const override;

        //* function that must be override
        virtual void printBuildingInformation() const = 0;

        //* Destructor
        virtual ~Building() override = default;
};

//* MultiStoreyBuilding
class MultiStoreyBuilding : public Building {
    private:
        size_t floors;
        size_t numberOfApartments;
    public:
        MultiStoreyBuilding(std::string_view _adress, size_t _floors, size_t _numberOfApartments, double _squareMeters, double _energyConsuming);
        void printBuildingInformation() const override;
};

//* Shopping center
class ShoppingCenter : public Building {
    private:
        size_t numberOfShops;
        size_t floors;
    public:
        ShoppingCenter(std::string_view _adress, size_t _floors, size_t _numberOfShops, double _squareMeters, double _energyConsuming);
        void printBuildingInformation() const override;
        
};

//* Factory
class Factory : public Building {
    private:
        size_t numberOfHalls;
    public:
        Factory(std::string_view _adress, size_t _numberOfHalls, double _squareMeters, double _energyConsuming);
        void printBuildingInformation() const override;
};

//* Farm
class Farm : public Building {
    private:
        size_t numberOfHalls;
    public:
        Farm(std::string_view _adress, size_t _numberOfHalls, double _squareMeters, double _energyConsuming);
        void printBuildingInformation() const override;
};


#endif // BUILDING_H