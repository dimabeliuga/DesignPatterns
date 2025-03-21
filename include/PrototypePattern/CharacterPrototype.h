#ifndef CHARACTER_PROTOTYPE_H
#define CHARACTER_PROTOTYPE_H

#include "Skill.h"
#include <memory>
#include <vector>


using rangeDouble = std::pair<double, double>;

class CharacterPrototype {
    protected:
        enum class CHARACTER_TYPE {WARRIOR, MAGE, ARCHER};
        const char* characterTypeToString(CHARACTER_TYPE type) const;

        struct Characteristics{
            size_t level;
            double health;
            double agility;
            double strength;
            double intelligence;
            CHARACTER_TYPE type;
            double bonusHealth = 0;
            double bonusAgility = 0;
            double bonusStrength = 0;
            double bonusIntelligence = 0;
            
            Characteristics(rangeDouble _health, 
                            rangeDouble _agility, 
                            rangeDouble _strength, 
                            rangeDouble _intelligence, 
                            CHARACTER_TYPE _type, 
                            size_t _level = 1);
            
            // Constructor for cloning
            Characteristics(double _health, 
                            double _agility, 
                            double _strength, 
                            double _intelligence, 
                            CHARACTER_TYPE _type, 
                            size_t _level)
                : health(_health), agility(_agility), 
                  strength(_strength), intelligence(_intelligence),
                  type(_type), level(_level) {}
            // Constructor for cloning
            Characteristics(const Characteristics& other)
                : health(other.health), agility(other.agility), 
                    strength(other.strength), intelligence(other.intelligence),
                    type(other.type), level(other.level) {}

            static double randomGenerator(rangeDouble generationRange);
        };

        std::unique_ptr<Characteristics> characteristics;
        std::vector<std::unique_ptr<Skill>> skills;
        
        void upgradeLevelHelper(double _health, double _agility, double _strength, double _intelligence);
    public:
        CharacterPrototype() = default;
        CharacterPrototype(std::unique_ptr<Characteristics> _characteristics)
                                : characteristics(std::move(_characteristics)) {} 
        virtual ~CharacterPrototype() = default;

        //* prohibiy copying and moving
        CharacterPrototype(const CharacterPrototype&) = delete;
        CharacterPrototype(CharacterPrototype&&) noexcept = delete;
        CharacterPrototype& operator=(const CharacterPrototype&) = delete;
        CharacterPrototype& operator=(CharacterPrototype&&) noexcept = delete;
        
        //* functions
        virtual void displayCharcterInformation() const;
        virtual void upgradeLevel() = 0;
        virtual std::unique_ptr<CharacterPrototype> clone() const = 0;
        
        void addSkill(std::unique_ptr<Skill> skill);
        void removeSkill(size_t index);
        void showAppliedSkills() const;
};


/*
    std::unique_ptr<CharacterPrototype> character = std::make_unique<Archer>();
    character -> displayCharcterInformation();
    auto giantStrength = std::make_unique<GiantStrength>();
    auto ironSkin = std::make_unique<IronSkin>();
    auto skillClone = ironSkin->clone();

    character -> addSkill(std::move(giantStrength));
    character -> addSkill(std::move(skillClone));
    character -> addSkill(std::move(ironSkin));
    
    auto clone = character -> clone();

    clone -> removeSkill(0);
    clone -> removeSkill(0);
    clone -> removeSkill(0);
    clone -> upgradeLevel();
    
    clone -> displayCharcterInformation();
    character ->displayCharcterInformation();
*/
#endif //CHARACTER_PROTOTYPE_H