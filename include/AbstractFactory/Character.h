#ifndef CHARACTER_H
#define CHARACTER_H

#include "Desctiption.h"
#include <iostream>

class Character {
    public:
        virtual void describe() const = 0;
        virtual ~Character() = default;
};

class FantasyWorldCharacter : public Character {
    public: 
        void describe() const override { 
            std::cout << "\nFantasy world character: \n" << Desctiptions::Character::fantasyCharacter << "\n\n"; 
        }
        ~FantasyWorldCharacter() = default;
};

class AncientWorldCharacter : public Character {
    public: 
        void describe() const override { 
            std::cout << "\nAncient world character: \n" << Desctiptions::Character::ancientCharacter << "\n\n"; 
        }
        ~AncientWorldCharacter() = default;
};

class SpaceWorldCharacter : public Character {
    public: 
        void describe() const override { 
            std::cout << "\nSpace world character: \n" << Desctiptions::Character::spaceCharacter<< "\n\n"; 
        }
        ~SpaceWorldCharacter() = default;
};

#endif //CHARACTER_H