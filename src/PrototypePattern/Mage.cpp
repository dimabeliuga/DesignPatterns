#include "Mage.h"

Mage::Mage() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble {70, 100},
        rangeDouble {60, 80},
        rangeDouble {70, 90},
        rangeDouble {100, 130},
        CHARACTER_TYPE::MAGE
    )) {}

Mage::Mage(const Mage &other) : CharacterPrototype(
    std::make_unique<Characteristics>(
        other.characteristics->health,
        other.characteristics->agility,
        other.characteristics->strength,
        other.characteristics->intelligence,
        other.characteristics->type,
        other.characteristics->level
    )) {}

std::unique_ptr<CharacterPrototype> Mage::clone() const{
    return std::make_unique<Mage>(*this);
}

void Mage::upgradeLevel(){
    upgradeLevelHelper(25, 15, 18, 23);
}
