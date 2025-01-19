#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Bard : public Jobs {
public:
    Bard() {
        Attributes bardAttributes = {
            .hp = 100.0f,
            .magicAttack = 25.0f,
            .physicalAttack = 20.0f,
            .magicDefense = 20.0f,
            .physicalDefense = 15.0f
        };

        Attributes bardModifiers = {
            .hp = 1.0f,
            .magicAttack = 1.3f,
            .physicalAttack = 1.1f,
            .magicDefense = 1.2f,
            .physicalDefense = 1.0f
        };

        Job bard = {
            .occupation = Classes::BARD,
            .description = "A charismatic performer, inspiring allies and confounding enemies with music and magic.",
            .attributes = bardAttributes,
            .modifiers = bardModifiers
        };

        setJob(bard);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Bard: You inspire and support your allies while weakening your enemies with your enchanting melodies.\n";
    }
};