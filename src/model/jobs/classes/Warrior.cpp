#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Warrior.hpp"

Warrior::Warrior() {
    Attributes warriorModifiers = {
        .hp = 1.3f,
        .magicAttack = 0.8f,
        .physicalAttack = 1.4f,
        .magicDefense = 1.0f,
        .physicalDefense = 1.2f
    };

    Job warrior = {
        .occupation = Classes::WARRIOR,
        .description = "A strong melee combatant excelling in physical attacks and defense.",
        .modifiers = warriorModifiers
    };

    setJob(warrior);
}

void Warrior::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
    currentAttributes.physicalAttack *= (level*5); 
    attributesProcessor.dealSpecialPhysicalDamage(currentAttributes.physicalAttack);

    std::cout << "Warrior: You excel in physical combat and defense, making you a frontline fighter.\n";
}