#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

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

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
        currentAttributes.physicalAttack *= (level*7); 
        attributesProcessor.dealSpecialPhysicalDamage(currentAttributes.physicalAttack);

        std::cout << "Ranger: Your expertise in ranged combat and survival makes you a versatile and deadly marksman.\n";
    }
};