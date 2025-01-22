#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Rogue : public Jobs {
public:
    Rogue() {
        Attributes rogueModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.0f,
            .physicalAttack = 1.3f,
            .magicDefense = 1.0f,
            .physicalDefense = 1.1f
        };

        Job rogue = {
            .occupation = Classes::ROGUE,
            .description = "A nimble and cunning fighter, skilled in evasion and precise attacks.",
            .modifiers = rogueModifiers
        };

        setJob(rogue);
    }

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

        Attributes buff{
            .hp = 0,
            .magicAttack = currentAttributes.magicAttack * 2,
            .physicalAttack = currentAttributes.physicalAttack * 3,
            .magicDefense = 0,
            .physicalDefense = 0,
        };

        int timer = 3;

        attributesProcessor.setModifiersEffect(timer, buff);

        std::cout << "Rogue: Your agility and cunning make you a deadly and elusive opponent.\n";
    }
};