#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Cleric : public Jobs {
public:
    Cleric() {
        Attributes clericAttributes = {
            .hp = 110.0f,
            .magicAttack = 30.0f,
            .physicalAttack = 15.0f,
            .magicDefense = 25.0f,
            .physicalDefense = 20.0f
        };

        Attributes clericModifiers = {
            .hp = 1.0f,
            .magicAttack = 1.4f,
            .physicalAttack = 0.9f,
            .magicDefense = 1.3f,
            .physicalDefense = 1.1f
        };

        Job cleric = {
            .occupation = Classes::CLERIC,
            .description = "A divine spellcaster, focused on healing and protecting allies through holy magic.",
            .attributes = clericAttributes,
            .modifiers = clericModifiers
        };

        setJob(cleric);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Cleric: You channel divine power to heal and protect your allies, ensuring their survival.\n";
    }
};