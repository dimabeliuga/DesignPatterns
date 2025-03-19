#ifndef SKILL_H
#define SKILL_H

#include <memory>

struct Bonus {
    double health = 0.0;
    double agility = 0.0;
    double strength = 0.0;
    double intelligence = 0.0;
};

class Skill {
    public:
        virtual ~Skill() = default;
        virtual void getBonus() = 0;
        virtual std::unique_ptr<Skill> clone()
};
#endif //SKILL_H