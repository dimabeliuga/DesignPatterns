#ifndef CHARACTER_PROTOTYPE_H
#define CHARACTER_PROTOTYPE_H

#include <memory>

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

            static double randomGenerator(rangeDouble generationRange);
        };

        std::unique_ptr<Characteristics> characteristics;
        
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
};

#endif //CHARACTER_PROTOTYPE_H