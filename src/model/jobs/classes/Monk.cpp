#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Monk : public Jobs {
public:
    Monk() {
        Attributes monkModifiers = {
            .hp = 1.1f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.2f,
            .magicDefense = 1.2f,
            .physicalDefense = 1.2f
        };

        Job monk = {
            .occupation = Classes::MONK,
            .description = "A disciplined combatant who channels spiritual energy into martial prowess.",
            .modifiers = monkModifiers
        };

        setJob(monk);
    }

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

        Attributes buff{
            .hp = 0,
            .magicAttack = 0,
            .physicalAttack = currentAttributes.physicalAttack * level,
            .magicDefense = currentAttributes.magicDefense * level,
            .physicalDefense = currentAttributes.physicalDefense * level,
        };

        int timer = 12;

        attributesProcessor.setModifiersEffect(timer, buff);

        std::cout << "Monk: Your discipline and spiritual energy make you a master of martial arts.";
    }
};