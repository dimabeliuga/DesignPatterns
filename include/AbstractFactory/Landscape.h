#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <iostream>

class Landscape {
    public: 
        virtual void describe() const = 0;
        virtual ~Landscape() = default;
};

class FantasyWorldLandscape : public Landscape {
    public: 
        void describe() const override { 
            std::cout << "\nFantasy World Landscape: \n" << Desctiptions::Landscapes::fantasyLandscapes << "\n\n";
        } 
        ~FantasyWorldLandscape() = default;
};

class AncientWorldLandscape : public Landscape {
    public: 
        void describe() const override { 
            std::cout << "\nAncient World landscapes: \n" << Desctiptions::Landscapes::ancientLandscapes << "\n\n"; 
        }
        ~AncientWorldLandscape() = default;
};

class SpaceWorldLandscape : public Landscape {
    public: 
        void describe() const override {
            std::cout << "\nSpace World landscapes: \n" << Desctiptions::Landscapes::spaceLandscapes << "\n\n"; 
        }
        ~SpaceWorldLandscape() = default;
};

#endif //LANDSCAPE_H
