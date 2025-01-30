#include <string>
#include <memory>
#include "../../model/races/include/RacesInterface.hpp"
#include "../../model/jobs/include/JobsInterface.hpp"
#include "../../model/races/include/RaceIncubator.hpp"
#include "../../model/jobs/include/JobIncubator.hpp"
#include "../../model/attributes/include/AttributesProcessor.hpp"
#include "TechnicalSheet.hpp"

/**
 * Constructor for the TechnicalSheet class.
 * Initializes the character's race, job, and attributes processor.
 *
 * @param level The character's level.
 * @param name The character's name.
 * @param species_ The character's species.
 * @param classes_ The character's class/job.
 */
TechnicalSheet::TechnicalSheet(
    int level,
    std::string name,
    Species species_,
    Classes classes_
) : name(name), level(level), species(species_), classes(classes_) {
    // Create the character's race and job using the incubators
    race = RaceIncubator::createRace(species);
    job = JobIncubator::createJob(classes);

    // Initialize the attributes processor with the character's race and job
    auto processor = new AttributesProcessor(race->getRace(), job->getJob());
    attributesProcessor = std::shared_ptr<AttributesProcessor>(processor);
}

/**
 * Uses the character's job skill.
 * Delegates the skill execution to the job object.
 */
void TechnicalSheet::useJobSkill() {
    job->skill(*attributesProcessor, level);
}

float TechnicalSheet::physicalAttack() {
    return attributesProcessor->getCurrentAttributes().physicalAttack;
}

float TechnicalSheet::magicalAttack() {
    return attributesProcessor->getCurrentAttributes().magicAttack;
}

/**
 * Applies magical damage to the character.
 * Delegates the damage calculation to the attributes processor.
 *
 * @param damage The amount of magical damage to be applied.
 */
void TechnicalSheet::receiveMagicalDamage(float damage) {
    attributesProcessor->takeMagicDamage(damage);
}

/**
 * Applies physical damage to the character.
 * Delegates the damage calculation to the attributes processor.
 *
 * @param damage The amount of physical damage to be applied.
 */
void TechnicalSheet::receivePhysicalDamage(float damage) {
    attributesProcessor->takePhysicalDamage(damage);
}

/**
 * Applies a temporary status effect to the character.
 * Delegates the effect application to the attributes processor.
 *
 * @param timer The duration of the effect.
 * @param attributes The attributes to be temporarily modified.
 */
void TechnicalSheet::applyStatusEffect(int timer, Attributes attributes) {
    attributesProcessor->setTemporaryAttributesStatusByTime(timer, attributes);
}

/**
 * Applies a temporary modifier effect to the character.
 * Delegates the effect application to the attributes processor.
 *
 * @param timer The duration of the effect.
 * @param attributes The attributes to be temporarily modified.
 */
void TechnicalSheet::aplyModifiersEffect(int timer, Attributes attributes) {
    attributesProcessor->setModifiersEffect(timer, attributes);
}

void TechnicalSheet::increaseDracmas(float amount) {
    dracmas += amount;
}

void TechnicalSheet::reduceDracmas(float amount) {
    dracmas -= amount;
}

/**
 * Increases the character's experience points (EXP).
 * If the current EXP exceeds the total required EXP, the character levels up.
 *
 * @param expReceived The amount of EXP to add.
 */
void TechnicalSheet::increaseExp(float expReceived) {
    currentExp += expReceived;
    while (currentExp >= totalExp) {
        currentExp -= totalExp;
        updateTotalExp();
        level++;
    }
}

void TechnicalSheet::updateTotalExp() {
    totalExp *= 1.5f;
}