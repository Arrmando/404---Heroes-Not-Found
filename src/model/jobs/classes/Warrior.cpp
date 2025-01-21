#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Warrior : public Jobs {
public:
    Warrior() {
        Attributes warriorModifiers = {
            .hp = 1.3f,
            .magicAttack = 0.8f,
            .physicalAttack = 1.4f,
            .magicDefense = 1.0f,
            .physicalDefense = 1.2f
        };

        Job warrior = {
            .occupation = Classes::WARRIOR,
            .description = "A strong melee combatant excelling in physical attacks and defense.",
            .modifiers = warriorModifiers
        };

        setJob(warrior);
    }

    void skill(float* damage, level) override {
        damage = damage*(level*5);
        std::cout << "Warrior: You excel in physical combat and defense, making you a frontline fighter.\n";
    }
};