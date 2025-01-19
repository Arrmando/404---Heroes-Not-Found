#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Ranger : public Jobs {
public:
    Ranger() {
        Attributes rangerAttributes = {
            .hp = 120.0f,
            .magicAttack = 15.0f,
            .physicalAttack = 30.0f,
            .magicDefense = 20.0f,
            .physicalDefense = 20.0f
        };

        Attributes rangerModifiers = {
            .hp = 1.1f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.4f,
            .magicDefense = 1.1f,
            .physicalDefense = 1.1f
        };

        Job ranger = {
            .occupation = Classes::RANGER,
            .description = "A master of ranged weapons and survival skills, excelling in precision and agility.",
            .attributes = rangerAttributes,
            .modifiers = rangerModifiers
        };

        setJob(ranger);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Ranger: Your expertise in ranged combat and survival makes you a versatile and deadly marksman.\n";
    }
};