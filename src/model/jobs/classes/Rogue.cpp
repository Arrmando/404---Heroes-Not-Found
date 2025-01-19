#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Rogue : public Jobs {
public:
    Rogue() {
        Attributes rogueAttributes = {
            .hp = 100.0f,
            .magicAttack = 15.0f,
            .physicalAttack = 25.0f,
            .magicDefense = 15.0f,
            .physicalDefense = 15.0f
        };

        Attributes rogueModifiers = {
            .hp = 1.0f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.3f,
            .magicDefense = 1.0f,
            .physicalDefense = 1.1f
        };

        Job rogue = {
            .occupation = Classes::ROGUE,
            .description = "A nimble and cunning fighter, skilled in evasion and precise attacks.",
            .attributes = rogueAttributes,
            .modifiers = rogueModifiers
        };

        setJob(rogue);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Rogue: Your agility and cunning make you a deadly and elusive opponent.\n";
    }
};