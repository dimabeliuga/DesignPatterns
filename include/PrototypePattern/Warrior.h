#ifndef WARRIOR_H
#define WARRIOR_H

#include "CharacterPrototype.h"

class Warrior : public CharacterPrototype {
    public: 
        Warrior();
        // Private constructor for cloning
        explicit Warrior(std::unique_ptr<Characteristics> chars);
        
        void upgradeLevel() override;
        std::unique_ptr<CharacterPrototype> clone() const override ;
};

#endif //WARRIOR_H