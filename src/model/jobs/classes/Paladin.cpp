#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Paladin : public Jobs {
public:
    Paladin() {
        Attributes paladinAttributes = {
            .hp = 140.0f,
            .magicAttack = 20.0f,
            .physicalAttack = 25.0f,
            .magicDefense = 30.0f,
            .physicalDefense = 25.0f
        };

        Attributes paladinModifiers = {
            .hp = 1.2f,
            .magicAttack = 1.1f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.3f,
            .physicalDefense = 1.2f
        };

        Job paladin = {
            .occupation = Classes::PALADIN,
            .description = "A holy warrior, combining physical strength with divine magic to protect and heal.",
            .attributes = paladinAttributes,
            .modifiers = paladinModifiers
        };

        setJob(paladin);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Paladin: You combine holy magic with martial prowess to shield and support your allies.\n";
    }
};