#include "Building.h"
#include <random>
#include <cassert>

//* Abstract Building class
std::string_view Building::buildingTypeToString() const
{
    switch (type)
    {
    case BUILDING_TYPE::RESIDENTIAL:  return "Residential";
    case BUILDING_TYPE::PUBLIC:       return "Public";
    case BUILDING_TYPE::INDUSTRIAL:   return "Industrial";
    case BUILDING_TYPE::AGRICULTURAL: return "Agricultural";

    default:  return "Unknown building type";
    }
}

Building::Building(BUILDING_TYPE _type, std::string_view _adress, double _squareMeters, double _energyConsuming)
    : type(_type), adress(_adress), squareMeters(_squareMeters), energyConsuming(_energyConsuming)
{
}

void Building::optimizeEnergy(size_t percentege)
{
    assert(percentege <= 100 && "Percentege can't be greater than 100");

    static std::random_device rd;
    static std::mt19937 mt(rd());
    static std::uniform_int_distribution<> gen(0, 100);
    if(gen(mt) <= percentege){
        std::cout << "Failed to reduce power consumption at adress " << adress << ". Try again!!!" << std::endl;
    } else {
        std::cout << "Power consumption decrised successfully at adress " << adress << std::endl;
        energyConsuming *= (100.0 - percentege) / 100.0;
    }
}

void Building::checkEnergyOverUse(size_t limit) const
{
    if(energyConsuming > limit){
        std::cout << "Energy consuming is greater than the set limit. Building adress" << adress << std::endl;
    } else {
        std::cout << "Energy consuming is less than the set limit. Building adress " << adress << std::endl;
    }
}

double Building::getTotalArea() const
{ 
    return squareMeters;
}

double Building::calculateEnergy() const
{
    return energyConsuming;
}

void Building::printStructure() const
{
    printBuildingInformation(); 
}

std::string Building::getAddress() const
{
    return adress;
}

//* MultiStoreyBuilding
MultiStoreyBuilding::MultiStoreyBuilding(std::string_view _adress, size_t _floors, size_t _numberOfApartments, double _squareMeters, double _energyConsuming)
        : floors(_floors), numberOfApartments(_numberOfApartments), Building(BUILDING_TYPE::RESIDENTIAL, _adress, _squareMeters, _energyConsuming)
{
}

void MultiStoreyBuilding::printBuildingInformation() const
{
    std::cout << "----" << buildingTypeToString() << " Building(Multi Storey)----" << std::endl
              << "Adress: " << adress << std::endl
              << "Floors: " << floors << std::endl
              << "Number of apartments: " << numberOfApartments << std::endl
              << "Total square meters: " << squareMeters << std::endl
              << "Total energy consuming: " << energyConsuming << std::endl
              << "----------------------------" << std::endl;
}

//* Shopping Center 
ShoppingCenter::ShoppingCenter(std::string_view _adress, size_t _floors, size_t _numberOfShops, double _squareMeters, double _energyConsuming)
        : floors(_floors), numberOfShops(_numberOfShops), Building(BUILDING_TYPE::PUBLIC, _adress, _squareMeters, _energyConsuming)
{
}

void ShoppingCenter::printBuildingInformation() const
{
    std::cout << "----" << buildingTypeToString() << " Building(Shopping Center)----" << std::endl
    << "Adress: " << adress << std::endl
    << "Floors: " << floors << std::endl
    << "Number of Shops: " << numberOfShops << std::endl
    << "Total square meters: " << squareMeters << std::endl
    << "Total energy consuming: " << energyConsuming << std::endl
    << "----------------------------" << std::endl;
}

Factory::Factory(std::string_view _adress, size_t _numberOfHalls, double _squareMeters, double _energyConsuming)
                : numberOfHalls(_numberOfHalls), Building(BUILDING_TYPE::INDUSTRIAL, _adress, _squareMeters, _energyConsuming)
{
}

void Factory::printBuildingInformation() const
{
    std::cout << "----" << buildingTypeToString() << " Building(Factory)----" << std::endl
    << "Adress: " << adress << std::endl
    << "Number of halls: " << numberOfHalls << std::endl
    << "Total square meters: " << squareMeters << std::endl
    << "Total energy consuming: " << energyConsuming << std::endl
    << "----------------------------" << std::endl;
}

//* Farm
Farm::Farm(std::string_view _adress, size_t _numberOfHalls, double _squareMeters, double _energyConsuming)
            : numberOfHalls(_numberOfHalls), Building(BUILDING_TYPE::AGRICULTURAL, _adress, _squareMeters, _energyConsuming)
{
}

void Farm::printBuildingInformation() const
{
    std::cout << "----" << buildingTypeToString() << " Building(Farm)----" << std::endl
    << "Adress: " << adress << std::endl
    << "Number of halls: " << numberOfHalls << std::endl
    << "Total square meters: " << squareMeters << std::endl
    << "Total energy consuming: " << energyConsuming << std::endl
    << "----------------------------" << std::endl;
}
