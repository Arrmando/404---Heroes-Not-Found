#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Sorcerer : public Jobs {
public:
    Sorcerer() {
        Attributes sorcererModifiers = {
            .hp = 0.8f,
            .magicAttack = 1.3f,
            .physicalAttack = 0.4f,
            .magicDefense = 1.3f,
            .physicalDefense = 0.8f
        };

        Job sorcerer = {
            .occupation = Classes::SORCERER,
            .description = "A wielder of innate magical power, capable of manipulating arcane forces.",
            .modifiers = sorcererModifiers
        };

        setJob(sorcerer);
    }

    void skill(AttributesProcessor& attributesProcessor, const int level) override {
        Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
        currentAttributes.magicAttack *= (level*7); 
        attributesProcessor.dealSpecialMagicalDamage(currentAttributes.magicAttack);

        std::cout << "Sorcerer: Your innate magic allows you to bend arcane forces to your will.";
    }
};