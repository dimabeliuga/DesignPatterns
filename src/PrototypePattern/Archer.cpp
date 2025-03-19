#include "Archer.h"

Archer::Archer() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble {50, 80},
        rangeDouble {60, 90},
        rangeDouble {40, 60},
        rangeDouble {60, 80},
        CHARACTER_TYPE::ARCHER
)) {}

Archer::Archer(const Archer& other) : CharacterPrototype(
    std::make_unique<Characteristics> (
        other.characteristics->health,
        other.characteristics->agility,
        other.characteristics->strength,
        other.characteristics->intelligence,
        other.characteristics->type,
        other.characteristics->level
    )
) {}

std::unique_ptr<CharacterPrototype> Archer::clone() const 
{
    return std::make_unique<Archer>(*this);
}

void Archer::upgradeLevel(){
    upgradeLevelHelper(15, 24, 10, 20);
}