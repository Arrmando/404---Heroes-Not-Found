#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Sorcerer : public Jobs {
public:
    Sorcerer() {
        Attributes sorcererAttributes = {
            .hp = 70.0f,
            .magicAttack = 45.0f,
            .physicalAttack = 5.0f,
            .magicDefense = 20.0f,
            .physicalDefense = 10.0f
        };

        Attributes sorcererModifiers = {
            .hp = 0.7f,
            .magicAttack = 1.6f,
            .physicalAttack = 0.6f,
            .magicDefense = 1.3f,
            .physicalDefense = 0.8f
        };

        Job sorcerer = {
            .occupation = Classes::SORCERER,
            .description = "A wielder of innate magical power, capable of manipulating arcane forces.",
            .attributes = sorcererAttributes,
            .modifiers = sorcererModifiers
        };

        setJob(sorcerer);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Sorcerer: Your innate magic allows you to bend arcane forces to your will.";
    }
};