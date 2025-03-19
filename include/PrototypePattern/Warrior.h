#ifndef WARRIOR_H
#define WARRIOR_H

#include "CharacterPrototype.h"
#include <memory>

class Warrior : public CharacterPrototype {
    public:  // Make constructor public
        Warrior();
        // Private constructor for cloning
        explicit Warrior(const Warrior& other);
        
        std::unique_ptr<CharacterPrototype> clone() const override ;

        void upgradeLevel() override;
};

#endif //WARRIOR_H