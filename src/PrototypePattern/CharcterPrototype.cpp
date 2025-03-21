#include "CharacterPrototype.h"
#include <iostream>
#include <random>

const char* CharacterPrototype::characterTypeToString(CharacterPrototype::CHARACTER_TYPE type) const {
    switch (type) {
        case CHARACTER_TYPE::WARRIOR: return "WARRIOR";
        case CHARACTER_TYPE::MAGE:    return "MAGE";
        case CHARACTER_TYPE::ARCHER:  return "ARCHER";
        default: return "UNKNOWN";
    }
}

CharacterPrototype::Characteristics::Characteristics(rangeDouble _health, rangeDouble _agility, rangeDouble _strength, rangeDouble _intelligence, CHARACTER_TYPE _type, size_t _level)
                 : level(_level), 
                   health(randomGenerator(_health)),
                   agility(randomGenerator(_agility)),
                   strength(randomGenerator(_strength)),
                   intelligence(randomGenerator(_intelligence)),
                   type(_type)
             {
             }

double CharacterPrototype::Characteristics::randomGenerator(rangeDouble generationRange){
    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_real_distribution<> gen(generationRange.first, generationRange.second);
    return gen(mt);
}
void CharacterPrototype::displayCharcterInformation() const {
    if(!characteristics){
        std::cout << "No character data available!\n";
        return ;
    }
    std::cout << "-------------------------------" << '\n'
              << "Type: " << characterTypeToString(characteristics->type) << '\n'
              << "Level: " << characteristics -> level << '\n'
              << "Health: " << characteristics -> health << '\n'
              << "Agility: " << characteristics -> agility << '\n'
              << "Strength: " << characteristics -> strength << '\n'
              << "Intelligence: " << characteristics -> intelligence << '\n'
              << "Apllied skills: " << skills.size() << '\n'
              << "Bonus Health: " << characteristics -> bonusHealth << '\n'
              << "Bonus Agility: " << characteristics -> bonusAgility << '\n'
              << "Bonus Strength: " << characteristics -> bonusStrength << '\n'
              << "Bonus Intelligence: " << characteristics -> bonusIntelligence << '\n'
              << "-------------------------------" << '\n';
}

void CharacterPrototype::addSkill(std::unique_ptr<Skill> skill) {
    if(!skill){
        std::cout << "You didn't specify any skill\n";
        return ;
    } 
    auto& bonus = skill -> bonus;
    if(!bonus.isAppliedToHero){
        characteristics -> bonusHealth += bonus.health;
        characteristics -> bonusAgility += bonus.agility;
        characteristics -> bonusStrength += bonus.strength;
        characteristics -> bonusIntelligence += bonus.intelligence;
        bonus.isAppliedToHero = true;

        skills.emplace_back(std::move(skill));
    }
}

void CharacterPrototype::removeSkill(size_t index){
    if(index >= skills.size()) {
        std::cout << "Error: incorect skill index of skill you want to remove!!!\n";
        return ;
    }

    const auto& bonus = skills[index] -> bonus;

    characteristics -> bonusHealth -= bonus.health;
    characteristics -> bonusAgility -= bonus.agility;
    characteristics -> bonusStrength -= bonus.strength;
    characteristics -> bonusIntelligence -= bonus.intelligence;
    //bonus.isAppliedToHero = false;


    skills.erase(skills.begin() + index);
}

void CharacterPrototype::showAppliedSkills() const{
    for(size_t i = 0; i < skills.size(); ++i) {
        std::cout << '\n' << "Skill index = " << i << '\n';
        skills[i]-> displaySkillInformation();
    }
}

void CharacterPrototype::upgradeLevelHelper(double _health, double _agility, double _strength, double _intelligence)
{
    characteristics -> level += 1;
    characteristics -> health += _health;
    characteristics -> agility += _agility;
    characteristics -> strength += _strength;
    characteristics -> intelligence += _intelligence;
}
