#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Monk : public Jobs {
public:
    Monk() {
        Attributes monkAttributes = {
            .hp = 100.0f,
            .magicAttack = 20.0f,
            .physicalAttack = 20.0f,
            .magicDefense = 20.0f,
            .physicalDefense = 20.0f
        };

        Attributes monkModifiers = {
            .hp = 1.1f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.2f,
            .physicalDefense = 1.2f
        };

        Job monk = {
            .occupation = Classes::MONK,
            .description = "A disciplined combatant who channels spiritual energy into martial prowess.",
            .attributes = monkAttributes,
            .modifiers = monkModifiers
        };

        setJob(monk);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Monk: Your discipline and spiritual energy make you a master of martial arts.";
    }
};