#include <iostream>
#include "../../../model/jobs/include/Jobs.hpp"
#include "../../../../utils/include/Attributes.hpp"
#include "../../../model/attributes/include/AttributesProcessor.hpp"
#include "Barbarian.hpp"

/**
 * Constructor for the Barbarian class.
 * Initializes the Barbarian job with specific modifiers and description.
 */
Barbarian::Barbarian() {
    Attributes barbarianModifiers = {
        .hp = 1.4f,
        .magicAttack = 0.5f,
        .physicalAttack = 1.5f,
        .magicDefense = 0.6f,
        .physicalDefense = 1.0f
    };
    Job barbarian = {
        .occupation = Classes::BARBARIAN,
        .description = "A fierce warrior fueled by rage, excelling in raw physical power.",
        .modifiers = barbarianModifiers
    };

    // Set the job using the protected method from the base class
    setJob(barbarian);
}

/**
 * Executes the Barbarian's skill.
 * Applies a temporary buff to the character's HP and physical attack based on their level.
 *
 * @param attributesProcessor The AttributesProcessor object to modify attributes.
 * @param level The character's level, used to scale the skill's effect.
 */
void Barbarian::skill(AttributesProcessor& attributesProcessor, const int level) {
    // Get the current attributes of the character
    Attributes currentAttributes = attributesProcessor.getCurrentAttributes();

    // Define the buff to be applied
    Attributes buff{
        .hp = currentAttributes.hp * 2 * level,
        .magicAttack = 0,
        .physicalAttack = currentAttributes.physicalAttack * 2 * level,
        .magicDefense = 0,
        .physicalDefense = 0,
    };

    // Set the duration of the buff
    int timer = 18;

    // Apply the buff using the AttributesProcessor
    attributesProcessor.setModifiersEffect(timer, buff);

    std::cout << "Barbarian: Your raw strength and ferocity make you a relentless force in battle." << std::endl;
}