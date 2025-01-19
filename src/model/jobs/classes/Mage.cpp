#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Mage : public Jobs {
public:
    Mage() {
        Attributes mageAttributes = {
            .hp = 80.0f,
            .magicAttack = 40.0f,
            .physicalAttack = 10.0f,
            .magicDefense = 25.0f,
            .physicalDefense = 10.0f
        };

        Attributes mageModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.5f,
            .physicalAttack = 0.7f,
            .magicDefense = 1.2f,
            .physicalDefense = 0.9f
        };

        Job mage = {
            .occupation = Classes::MAGE,
            .description = "A master of magical arts, specializing in high magical damage and support.",
            .attributes = mageAttributes,
            .modifiers = mageModifiers
        };

        setJob(mage);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Mage: You wield powerful magic, capable of devastating enemies and aiding allies.\n";
    }
};
