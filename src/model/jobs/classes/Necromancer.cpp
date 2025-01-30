#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Necromancer.hpp"

Necromancer::Necromancer() {
    Attributes necromancerModifiers = {
        .hp = 0.7f,
        .magicAttack = 1.7f,
        .physicalAttack = 0.6f,
        .magicDefense = 1.2f,
        .physicalDefense = 0.8f
    };

    Job necromancer = {
        .occupation = Classes::NECROMANCER,
        .description = "A master of death magic, capable of raising undead minions and cursing foes.",
        .modifiers = necromancerModifiers
    };

    setJob(necromancer);
}

void Necromancer::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

    Attributes buff{
        .hp = currentAttributes.hp * level,
        .magicAttack = currentAttributes.magicAttack * level,
        .physicalAttack = 0,
        .magicDefense = currentAttributes.magicDefense * level,
        .physicalDefense = 0,
    };

    int timer = 12;

    attributesProcessor.setModifiersEffect(timer, buff);

    std::cout << "Necromancer: Your dark magic allows you to control death itself.";
}