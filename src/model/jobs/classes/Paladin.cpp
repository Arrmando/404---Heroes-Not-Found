#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Paladin.hpp"

Paladin::Paladin() {
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
        .modifiers = paladinModifiers
    };

    setJob(paladin);
}

void Paladin::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

    Attributes buff{
        .hp = currentAttributes.hp * (level/3),
        .magicAttack = currentAttributes.magicAttack * (level/3),
        .physicalAttack = currentAttributes.physicalAttack * (level/3),
        .magicDefense = currentAttributes.magicDefense * (level/2),
        .physicalDefense = currentAttributes.physicalDefense * (level/2),
    };

    int timer = 6;

    attributesProcessor.setModifiersEffect(timer, buff);

    std::cout << "Paladin: You combine holy magic with martial prowess to shield and support your allies.\n";
}