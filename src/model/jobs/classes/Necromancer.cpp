#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Necromancer : public Jobs {
public:
    Necromancer() {
        Attributes necromancerAttributes = {
            .hp = 70.0f,
            .magicAttack = 50.0f,
            .physicalAttack = 5.0f,
            .magicDefense = 20.0f,
            .physicalDefense = 10.0f
        };

        Attributes necromancerModifiers = {
            .hp = 0.7f,
            .magicAttack = 1.7f,
            .physicalAttack = 0.6f,
            .magicDefense = 1.2f,
            .physicalDefense = 0.8f
        };

        Job necromancer = {
            .occupation = Classes::NECROMANCER,
            .description = "A master of death magic, capable of raising undead minions and cursing foes.",
            .attributes = necromancerAttributes,
            .modifiers = necromancerModifiers
        };

        setJob(necromancer);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Necromancer: Your dark magic allows you to control death itself.";
    }
};