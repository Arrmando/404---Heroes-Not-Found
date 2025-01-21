#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Mage : public Jobs {
public:
    Mage() {
        Attributes mageModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.5f,
            .physicalAttack = 0.7f,
            .magicDefense = 1.2f,
            .physicalDefense = 0.8f
        };

        Job mage = {
            .occupation = Classes::MAGE,
            .description = "A master of magical arts, specializing in high magical damage and support.",
            .modifiers = mageModifiers
        };

        setJob(mage);
    }

    void skill() override {
        void skill(float* damage, level) override {
        damage = damage*(level*5);
        std::cout << "Mage: You wield powerful magic, capable of devastating enemies and aiding allies.\n";

    }
};
