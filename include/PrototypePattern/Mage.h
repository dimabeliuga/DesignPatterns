#ifndef MAGE_H
#define MAGE_H

#include "CharacterPrototype.h"

class Mage : public CharacterPrototype {
    public:
        Mage();
        explicit Mage(std::unique_ptr<Characteristics> chars);
        void upgradeLevel() override;
        std::unique_ptr<CharacterPrototype> clone() const override;
};

#endif // MAGE_H