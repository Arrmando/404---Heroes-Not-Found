#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {
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

void Sorcerer::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
    currentAttributes.magicAttack *= (level*7); 
    attributesProcessor.dealSpecialMagicalDamage(currentAttributes.magicAttack);

    std::cout << "Sorcerer: Your innate magic allows you to bend arcane forces to your will.";
}