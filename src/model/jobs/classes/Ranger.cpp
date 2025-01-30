#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Ranger.hpp"

Ranger::Ranger() {
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

void Ranger::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();
    currentAttributes.physicalAttack *= (level*7); 
    attributesProcessor.dealSpecialPhysicalDamage(currentAttributes.physicalAttack);

    std::cout << "Ranger: Your expertise in ranged combat and survival makes you a versatile and deadly marksman.\n";
}