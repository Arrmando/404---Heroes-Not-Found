#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Warrior : public Jobs {
public:
    Warrior() {
        Attributes warriorAttributes = {
            .hp = 150.0f,
            .magicAttack = 10.0f,
            .physicalAttack = 30.0f,
            .magicDefense = 15.0f,
            .physicalDefense = 25.0f
        };

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
            .attributes = warriorAttributes,
            .modifiers = warriorModifiers
        };

        setJob(warrior);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Warrior: You excel in physical combat and defense, making you a frontline fighter.\n";
    }
};