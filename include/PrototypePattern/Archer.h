#ifndef ARCHER_H
#define ARCHER_H

#include "CharacterPrototype.h"
#include <memory>

class Archer : public CharacterPrototype {
    public:
        Archer();
        explicit Archer(const Archer& other);

        std::unique_ptr<CharacterPrototype> clone() const override;
        void upgradeLevel() override;
};
#endif