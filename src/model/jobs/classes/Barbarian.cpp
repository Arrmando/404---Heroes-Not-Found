#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Barbarian : public Jobs {
public:
    Barbarian() {
        Attributes barbarianAttributes = {
            .hp = 180.0f,
            .magicAttack = 10.0f,
            .physicalAttack = 35.0f,
            .magicDefense = 10.0f,
            .physicalDefense = 20.0f
        };

        Attributes barbarianModifiers = {
            .hp = 1.4f,
            .magicAttack = 0.8f,
            .physicalAttack = 1.5f,
            .magicDefense = 0.9f,
            .physicalDefense = 1.0f
        };

        Job barbarian = {
            .occupation = Classes::BARBARIAN,
            .description = "A fierce warrior fueled by rage, excelling in raw physical power.",
            .attributes = barbarianAttributes,
            .modifiers = barbarianModifiers
        };

        setJob(barbarian);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Barbarian: Your raw strength and ferocity make you a relentless force in battle.";
    }
};