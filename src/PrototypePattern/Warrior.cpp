#include "Warrior.h"

Warrior::Warrior() : CharacterPrototype(
    std::make_unique<Characteristics>(
        rangeDouble {100,150},  //health
        rangeDouble {30, 50},   //agility
        rangeDouble {70, 100},  //strength
        rangeDouble {20, 40},   // intelligence
        CHARACTER_TYPE::WARRIOR //type
        // level = 1 (by default but you can input any level you want) 
    )) 
{
}

Warrior::Warrior(std::unique_ptr<Characteristics> chars) 
            : CharacterPrototype(std::move(chars)) 
{
}
    

std::unique_ptr<CharacterPrototype> Warrior::clone() const
{
    auto clonedCharacteristics = std::make_unique<Characteristics>(
        characteristics->health,
        characteristics->agility,
        characteristics->strength,
        characteristics->intelligence,
        characteristics->type,
        characteristics->level
    );
    auto cloneWarrior = std::make_unique<Warrior>(std::move(clonedCharacteristics));
    for (const auto& skill : skills) {
        cloneWarrior->addSkill(skill->clone());
    }
    return cloneWarrior;
}

void Warrior::upgradeLevel() 
{
    upgradeLevelHelper(30, 12, 22, 8);
}
