
#include "WorldFactory.h"
#include "Desctiption.h"
#include <random>

//* FantasyWorldFactory
void FantasyWorldFactory::createLandscapes() {
    landscape = std::make_unique<FantasyWorldLandscape>(); 
}
void FantasyWorldFactory::createCharacter() {
    character = std::make_unique<FantasyWorldCharacter>();
}
void FantasyWorldFactory::createWeapon() {
    weapon = std::make_unique<FantasyWorldWeapon>();
} 
void FantasyWorldFactory::createTransport() {
    transport = std::make_unique<FantasyWorldTransport>();
}

//* AncientWorldFactory
void AncientWorldFactory::createLandscapes(){
    landscape = std::make_unique<AncientWorldLandscape>(); 
}
void AncientWorldFactory::createCharacter() {
    character = std::make_unique<AncientWorldCharacter>();
}
void AncientWorldFactory::createWeapon(){
    weapon = std::make_unique<AncientWorldWeapon>();
} 
void AncientWorldFactory::createTransport() {
    transport = std::make_unique<AncientWorldTransport>();
}

//* Space world Factory
void SpaceWorldFactory::createLandscapes(){
    landscape = std::make_unique<SpaceWorldLandscape>(); 
}
void SpaceWorldFactory::createCharacter() {
    character = std::make_unique<SpaceWorldCharacter>();
}
void SpaceWorldFactory::createWeapon(){
    weapon = std::make_unique<SpaceWorldWeapon>();
} 
void SpaceWorldFactory::createTransport() {
    transport = std::make_unique<SpaceWorldTransport>();
}

//* WorldCreator
void WorldCreator::createRandomWorld() {
    if(worldFactory){
        throw std::runtime_error("The world has been created");
    }
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<> gen(0, getNumberOfFactories() - 1);
    switch (gen(mt))
    {
    case 0:
        worldFactory = std::make_unique<FantasyWorldFactory>();
        break;
    case 1:
        worldFactory = std::make_unique<AncientWorldFactory>();
        break;
    case 2:
        worldFactory = std::make_unique<SpaceWorldFactory>();
        break;
    default:
        throw std::runtime_error ("Error: problem with random generator");
        break;
    }
    worldFactory -> createCharacter();
    worldFactory -> createLandscapes();
    worldFactory -> createTransport();
    worldFactory -> createWeapon();
}

void WorldCreator::outputWorldInformation() const{
    worldFactory -> character -> describe();
    worldFactory -> landscape -> describe();
    worldFactory -> transport -> describe();
    worldFactory -> weapon    -> describe();
}

unsigned short WorldCreator::getNumberOfFactories() { 
    static unsigned short numberOfFactories = 3; 
    return numberOfFactories;
}
