#include "CharacterPrototype.h"
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"

#include <iostream>

int main() {
    std::unique_ptr<CharacterPrototype> character = std::make_unique<Mage>();
    character -> displayCharcterInformation();

    auto clone = character -> clone();
    clone -> displayCharcterInformation();

    character -> upgradeLevel();
    character -> displayCharcterInformation();
    clone -> displayCharcterInformation();
    return 0;
}