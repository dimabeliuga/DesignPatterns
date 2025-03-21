#ifndef SKILL_H
#define SKILL_H

#include <memory>
#include <string>

struct Bonus {
    std::string description;
    double health = 0.0;
    double agility = 0.0;
    double strength = 0.0;
    double intelligence = 0.0;
    bool isAppliedToHero = false;

    Bonus(const char* _description, 
                   double _health, 
                   double _agility, 
                   double _strength,
                   double _intelligence
                ) 
                : description(_description),
                health(_health),
                agility(_agility),
                strength(_strength),
                intelligence(_intelligence) {}

    Bonus(const Bonus& bonus) : 
                description(bonus.description),
                health(bonus.health),
                agility(bonus.agility),
                strength(bonus.strength),
                intelligence(bonus.intelligence) {}

};

class Skill {
    public:
        Bonus bonus;
        Skill(const char* _description, 
                       double _health, 
                       double _agility, 
                       double _strength,
                       double _intelligence
                    ) : bonus(_description, 
                              _health, 
                              _agility, 
                              _strength, 
                              _intelligence) 
                    {
                    }
        
        Skill(const Bonus& _bonus) : bonus(_bonus) {}
        virtual ~Skill() = default;
        virtual std::unique_ptr<Skill> clone() = 0;
        virtual void displaySkillInformation() const;
};

class GiantStrength : public Skill {
    public:
        GiantStrength() : Skill("Giant Strength", 10.0, 0.0, 15.0, 0.0) {}
        explicit GiantStrength(const Bonus& _bonus) : Skill(_bonus) {}

        std::unique_ptr<Skill> clone() override;
};

class SwiftStep : public Skill {
    public:
        SwiftStep() : Skill("Swift Step", 0.0, 15.0, 0.0, 0.0 ) {}
        explicit SwiftStep(const Bonus& _bonus) : Skill(_bonus) {}

        std::unique_ptr<Skill> clone() override;
};

class ArcaneIntellect : public Skill {
    public:
    ArcaneIntellect() : Skill("Arcane Intellect", 0.0, 8.0, 0.0, 17.0) {}
        explicit ArcaneIntellect(const Bonus& _bonus) : Skill(_bonus) {}

        std::unique_ptr<Skill> clone() override;
};

class IronSkin : public Skill {
    public:
        IronSkin() : Skill("Iron Skin", 20.0, 0.0, 0.0, 0.0) {}
        explicit IronSkin(const Bonus& _bonus) : Skill(_bonus) {}

        std::unique_ptr<Skill> clone() override;
};


#endif //SKILL_H