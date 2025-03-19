#include "Warrior.h"

Warrior::Warrior() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble {100,150},  //health
        rangeDouble {30, 50},   //agility
        rangeDouble {70, 100},  //strength
        rangeDouble {20, 40},   // intelligence
        CHARACTER_TYPE::WARRIOR //type
        // level = 1 (by default but you can input any level you want) 
    )) {}

std::unique_ptr<CharacterPrototype> Warrior::clone() const
{
    return std::make_unique<Warrior>(*this);
}

void Warrior::upgradeLevel() 
{
    upgradeLevelHelper(30, 12, 22, 8);
}

Warrior::Warrior(const Warrior& other) : CharacterPrototype(
    std::make_unique<Characteristics>(
        other.characteristics->health,
        other.characteristics->agility,
        other.characteristics->strength,
        other.characteristics->intelligence,
        other.characteristics->type,
        other.characteristics->level
    )) {}
