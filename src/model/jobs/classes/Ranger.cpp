#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Ranger : public Jobs {
public:
    Ranger() {
        Attributes rangerModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.0f,
            .physicalDefense = 1.2f
        };

        Job ranger = {
            .occupation = Classes::RANGER,
            .description = "A master of ranged weapons and survival skills, excelling in precision and agility.",
            .modifiers = rangerModifiers
        };

        setJob(ranger);
    }

    void skill() override {
        void skill(float* damage, level) override {
        damage = damage*(level*7);

        std::cout << "Ranger: Your expertise in ranged combat and survival makes you a versatile and deadly marksman.\n";
    }
};