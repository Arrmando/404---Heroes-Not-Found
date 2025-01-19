#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Druid : public Jobs {
public:
    Druid() {
        Attributes druidAttributes = {
            .hp = 90.0f,
            .magicAttack = 30.0f,
            .physicalAttack = 15.0f,
            .magicDefense = 25.0f,
            .physicalDefense = 15.0f
        };

        Attributes druidModifiers = {
            .hp = 1.0f,
            .magicAttack = 1.4f,
            .physicalAttack = 1.0f,
            .magicDefense = 1.3f,
            .physicalDefense = 1.0f
        };

        Job druid = {
            .occupation = Classes::DRUID,
            .description = "A guardian of nature, capable of shapeshifting and wielding natural magic.",
            .attributes = druidAttributes,
            .modifiers = druidModifiers
        };

        setJob(druid);
    }

protected:
    void setJobSpecialTrait() override {
        std::cout << "Druid: Your connection to nature grants you unique powers and versatility.";
    }
};