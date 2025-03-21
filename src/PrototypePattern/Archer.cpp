#include "Archer.h"

Archer::Archer() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble {50, 80},
        rangeDouble {60, 90},
        rangeDouble {40, 60},
        rangeDouble {60, 80},
        CHARACTER_TYPE::ARCHER
)) {}

Archer::Archer(std::unique_ptr<Characteristics> chars) 
                : CharacterPrototype(std::move(chars))
{
}

std::unique_ptr<CharacterPrototype> Archer::clone() const 
{
    auto clonedCharacteristics = std::make_unique<Characteristics>(
        characteristics->health,
        characteristics->agility,
        characteristics->strength,
        characteristics->intelligence,
        characteristics->type,
        characteristics->level
    );
    auto cloneArcher = std::make_unique<Archer>(std::move(clonedCharacteristics));
    for (const auto& skill : skills) {
        cloneArcher->addSkill(skill->clone());
    }
    return cloneArcher;
}

void Archer::upgradeLevel(){
    upgradeLevelHelper(15, 24, 10, 20);
}