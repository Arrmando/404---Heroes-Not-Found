#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

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

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
        currentAttributes.magicAttack *= (level*5); 
        attributesProcessor.dealSpecialMagicalDamage(currentAttributes.magicAttack);

        std::cout << "Mage: You wield powerful magic, capable of devastating enemies and aiding allies.\n";

    }
};
