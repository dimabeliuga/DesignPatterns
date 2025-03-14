#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class Weapon {
    public:
        virtual void describe() const = 0;
        virtual ~Weapon() = default;
};

class FantasyWorldWeapon : public Weapon {
    public: 
        void describe() const override {
            std::cout << "\nFantasy world weapon: \n" << Desctiptions::Weapon::fantasyWeapon << "\n\n";
        } 
        ~FantasyWorldWeapon() = default;
};

class AncientWorldWeapon : public Weapon {
    public: 
        void describe() const override {
            std::cout << "\nAncient world weapon: \n" << Desctiptions::Weapon::ancientWeapon << "\n\n";
        } 
        ~AncientWorldWeapon() = default;
};

class SpaceWorldWeapon : public Weapon {
    public: 
        void describe() const override {
            std::cout << "\nSpace world weapon: \n" << Desctiptions::Weapon::spaceWeapon << "\n\n";
        } 
        ~SpaceWorldWeapon() = default;
};

#endif //WEAPON_H