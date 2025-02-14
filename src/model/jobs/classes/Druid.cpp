#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Druid.hpp"

Druid::Druid() {
    Attributes druidModifiers = {
        .hp = 1.3f,
        .magicAttack = 1.3f,
        .physicalAttack = 1.2f,
        .magicDefense = 1.2f,
        .physicalDefense = 1.1f
    };

    Job druid = {
        .occupation = Classes::DRUID,
        .description = "A guardian of nature, capable of shapeshifting and wielding natural magic.",
        .modifiers = druidModifiers
    };

    setJob(druid);
}

void Druid::skill(AttributesProcessor& attributesProcessor, const int level) {
    Attributes totalAttributes = attributesProcessor.getTotalAttributes();

    totalAttributes.hp *= (0.1+(0.1*level));
    attributesProcessor.restoreHealth(totalAttributes.hp);

    std::cout << "Druid: Your connection to nature grants you unique powers and versatility.";
}