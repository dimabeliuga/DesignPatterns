#include "Mage.h"

Mage::Mage() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble{70, 100},
        rangeDouble{60, 80},
        rangeDouble{70, 90},
        rangeDouble{100, 130},
        CHARACTER_TYPE::MAGE
    ))
{
}

Mage::Mage(std::unique_ptr<Characteristics> chars) 
    : CharacterPrototype(std::move(chars))
{
}

std::unique_ptr<CharacterPrototype> Mage::clone() const {
    auto clonedCharacteristics = std::make_unique<Characteristics>(
        characteristics->health,
        characteristics->agility,
        characteristics->strength,
        characteristics->intelligence,
        characteristics->type,
        characteristics->level
    );
    auto cloneMage = std::make_unique<Mage>(std::move(clonedCharacteristics));
    for (const auto& skill : skills) {
        cloneMage->addSkill(skill->clone());
    }
    return cloneMage;
}

void Mage::upgradeLevel() {
    upgradeLevelHelper(5.0, 8.0, 5.0, 15.0); 
}