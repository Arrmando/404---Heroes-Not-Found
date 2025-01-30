#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Cleric.hpp"

Cleric::Cleric() {
    Attributes clericModifiers = {
        .hp = 1.0f,
        .magicAttack = 1.3f,
        .physicalAttack = 0.8f,
        .magicDefense = 1.4f,
        .physicalDefense = 1.0f
    };

    Job cleric = {
        .occupation = Classes::CLERIC,
        .description = "A divine spellcaster, focused on healing and protecting allies through holy magic.",
        .modifiers = clericModifiers
    };

    setJob(cleric);
}

void Cleric::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes totalAttributes = attributesProcessor.getTotalAttributes();

    totalAttributes.hp *= (0.2+(0.02*level));
    attributesProcessor.restoreHealth(totalAttributes.hp);
    
    std::cout << "Cleric: You channel divine power to heal and protect your allies, ensuring their survival.\n";
}




