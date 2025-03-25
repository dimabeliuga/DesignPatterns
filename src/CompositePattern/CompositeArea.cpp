#include "CompositeArea.h"
#include <numeric>

std::string_view CompositeArea::areaTypeToString() const
{
    switch (areaType)
    {
        case AREA_TYPE::VILLAGE: return "Village";
        case AREA_TYPE::REGION : return "Region";
        case AREA_TYPE::CITY   : return "City";
        default: return "Unknown Area Type";
    }
}

//* Main class - Composite Area
CompositeArea::CompositeArea(AREA_TYPE _areaType, std::string_view _areaName)
                    : areaType(_areaType), areaName(_areaName)
{
}

double CompositeArea::getTotalArea() const
{
    return std::accumulate(buildings.begin(), buildings.end(), 0.0, 
        [](double sum, const std::unique_ptr<CityComponent>& building)
        {
            return sum + building -> getTotalArea();
        });
}

double CompositeArea::calculateEnergy() const
{
    return std::accumulate(buildings.begin(), buildings.end(), 0.0, 
        [](double sum, const std::unique_ptr<CityComponent>& building)
        {
            return sum + building -> calculateEnergy();
        });
}

void CompositeArea::printStructure() const
{
    std::cout << "↓↓↓↓Area structure(" << areaTypeToString() << ")↓↓↓↓" << std::endl;
    for(const auto &iter : buildings){
        iter -> printStructure();
    }
}

void CompositeArea::optimizeEnergy(size_t percentage)
{
    for(auto &iter : buildings){
        iter -> optimizeEnergy(percentage);
    }
}

void CompositeArea::checkEnergyOverUse(size_t limit) const
{
    for(const auto &iter : buildings){
        iter->checkEnergyOverUse(limit);
    }
}

std::string CompositeArea::getAddress() const
{
    return areaName;
}

void CompositeArea::removeComponent(std::string_view adress)
{
    for(auto iter = buildings.begin(); iter != buildings.end();){
        if((*iter)->getAddress() == adress){
            iter = buildings.erase(iter);
            std::cout << "Building with adress: " << adress << " has been deleted" << std::endl;
        } else {
            ++iter;
        }
    }
}

void CompositeArea::addComponent(std::unique_ptr<CityComponent> building)
{
    buildings.emplace_back(std::move(building));
}


//* Village

Village::Village(std::string_view areaName)
                : CompositeArea(AREA_TYPE::VILLAGE, areaName)
{
}

//* City
City::City(std::string_view areaName)
                : CompositeArea(AREA_TYPE::CITY, areaName)
{
}

//* Region
Region::Region(std::string_view areaName)
                : CompositeArea(AREA_TYPE::REGION, areaName)
{
}

