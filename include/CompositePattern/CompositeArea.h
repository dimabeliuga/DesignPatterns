#ifndef COMPOSITE_AREA_H
#define COMPOSITE_AREA_H

#include "Building.h"
#include <vector>
#include <memory>

enum class AREA_TYPE {VILLAGE, CITY, REGION};

class CompositeArea : public CityComponent{
    protected:
        std::vector<std::unique_ptr<CityComponent>> buildings;
        AREA_TYPE areaType;
        std::string areaName;

        std::string_view areaTypeToString() const;
    public:
        //* Constuctor
        CompositeArea(AREA_TYPE _areaType, std::string_view _areaName);
        
        //* Deleted constructors
        CompositeArea(const CompositeArea&) = delete;
        CompositeArea(CompositeArea&&) noexcept = delete;
        CompositeArea& operator=(const CompositeArea&) = delete;
        CompositeArea& operator=(CompositeArea&&) = delete;

        //* Override functions
        double getTotalArea() const override;
        double calculateEnergy() const override;
        void printStructure() const override;
        void optimizeEnergy(size_t percentage) override;
        void checkEnergyOverUse(size_t limit) const override;
        std::string getAddress() const override;
        
        //* Extra functions
        virtual void removeComponent(std::string_view adress);
        virtual void addComponent(std::unique_ptr<CityComponent> building);
};

class Village : public CompositeArea {
    public:
        explicit Village(std::string_view areaName);
};

class City : public CompositeArea {
    public:
        explicit City(std::string_view areaName);
};

class Region : public CompositeArea {
    public:
        explicit Region(std::string_view areaName);
};

#endif //COMPOSITE_AREA_H
