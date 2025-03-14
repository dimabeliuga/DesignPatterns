#ifndef WORLD_FACTORY_H
#define WORLD_FACTORY_H

#include <memory>
#include "Desctiption.h"
#include "Character.h"
#include "Landscape.h"
#include "Transport.h"
#include "Weapon.h"

//* abstract world factory("template" for all factories) 
class WorldFactory {
    public:
        virtual void createLandscapes() = 0;
        virtual void createCharacter()  = 0;
        virtual void createWeapon()     = 0;
        virtual void createTransport()  = 0;
        virtual ~WorldFactory() = default;

        WorldFactory() : landscape(nullptr), character(nullptr), weapon(nullptr), transport(nullptr) {}

    public:
        std::unique_ptr<Landscape> landscape;
        std::unique_ptr<Character> character;
        std::unique_ptr<Weapon>    weapon;
        std::unique_ptr<Transport> transport;
};

//* Fantasy World
class FantasyWorldFactory : public WorldFactory {
    public: 
        FantasyWorldFactory() : WorldFactory() {}

        void createLandscapes() override;
        void createCharacter() override;
        void createWeapon() override;
        void createTransport() override;
        ~FantasyWorldFactory() = default;
};

//* Ancient World
class AncientWorldFactory : public WorldFactory {
    public: 
        AncientWorldFactory() : WorldFactory() {}

        void createLandscapes() override;
        void createCharacter() override;
        void createWeapon() override;
        void createTransport() override;
        ~AncientWorldFactory() = default;
};

//* Space world
class SpaceWorldFactory : public WorldFactory {
    public: 
        SpaceWorldFactory() : WorldFactory() {}

        void createLandscapes() override;
        void createCharacter() override;
        void createWeapon() override;
        void createTransport() override;
        ~SpaceWorldFactory() = default;
};

class WorldCreator {
    private:
        std::unique_ptr<WorldFactory> worldFactory;

    public:
        WorldCreator() : worldFactory(nullptr) {}
        void createRandomWorld();
        void outputWorldInformation();
    private:
        static unsigned short getNumberOfFactories();
};

#endif //ABSTRACT_FACTORY_H