#ifndef MAG_H
#define MAG_H

#include "CharacterPrototype.h"
#include <memory>

class Mage : public CharacterPrototype {
    public:
        Mage();
        explicit Mage(const Mage& other);

        std::unique_ptr<CharacterPrototype> clone() const override;
        void upgradeLevel() override;
};
#endif //MAG_H