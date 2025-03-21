#ifndef ARCHER_H
#define ARCHER_H

#include "CharacterPrototype.h"

class Archer : public CharacterPrototype {
    public:
        Archer();
        explicit Archer(std::unique_ptr<Characteristics> chars);
        void upgradeLevel() override;
        std::unique_ptr<CharacterPrototype> clone() const override;
};
#endif