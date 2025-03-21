#include "Skill.h"
#include <iostream>

std::unique_ptr<Skill> GiantStrength::clone() {
    return std::make_unique<GiantStrength>(this -> bonus);
}

std::unique_ptr<Skill> SwiftStep::clone(){
    return std::make_unique<SwiftStep>(this -> bonus);
}

std::unique_ptr<Skill> ArcaneIntellect::clone(){
    return std::make_unique<ArcaneIntellect>(this -> bonus);
}

std::unique_ptr<Skill> IronSkin::clone(){
    return std::make_unique<IronSkin>(this -> bonus);
}

void Skill::displaySkillInformation() const{
    std::cout << "----------------------------" << '\n'
              << "Name: " << bonus.description << '\n'
              << "Health: " << bonus.health << '\n'
              << "Agility: " << bonus.agility << '\n'
              << "Strength: " << bonus.strength << '\n'  
              << "Intelligence: " << bonus.intelligence << '\n'
              << "Is applied to hero: " << std::boolalpha << bonus.isAppliedToHero << '\n'
              << "----------------------------" << '\n';
}
