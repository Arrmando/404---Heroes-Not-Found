#include <iostream>
#include <algorithm>
#include <memory>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <cppcoro/io_service.hpp>
#include "../../../utils/include/AttibutesType.hpp"
#include "../../../utils/include/Race.hpp"
#include "../../../utils/include/Job.hpp"
#include "../../../utils/include/Attributes.hpp"
#include "../../../utils/include/Corroutines.hpp"
#include "../../model/modifiers/include/ModifiersProcessor.hpp"
#include "./include/AttributesProcessor.hpp"

AttributesProcessor::AttributesProcessor(
        Race race_,
        Job job_
    ) : race(race_), 
        job(job_), 
        modifiersProcessor(std::ref(race.modifiers),std::ref(job.modifiers)) {}

void AttributesProcessor::updateRaceAttributes(const unsigned int level) {
    race.attributes.hp += race.attributes.hp * modifiersProcessor.getHpModifier(AttributesType::RACE) * level;
    race.attributes.magicAttack += race.attributes.magicAttack * modifiersProcessor.getMagicAttackModifier(AttributesType::RACE) * level;
    race.attributes.magicDefense += race.attributes.magicDefense * modifiersProcessor.getMagicDefenseModifier(AttributesType::RACE) * level;
    race.attributes.physicalAttack += race.attributes.physicalAttack * modifiersProcessor.getPhysicalAttackModifier(AttributesType::RACE) * level;
    race.attributes.physicalDefense += race.attributes.physicalDefense * modifiersProcessor.getPhysicalDefenseModifier(AttributesType::RACE) * level;
}

void AttributesProcessor::calculateTotalAttributes() {
    totalAttributes.hp = modifiersProcessor.getHpModifier(AttributesType::JOB) + race.attributes.hp;
    totalAttributes.magicAttack = modifiersProcessor.getMagicAttackModifier(AttributesType::JOB) + race.attributes.magicAttack;
    totalAttributes.magicDefense = modifiersProcessor.getMagicDefenseModifier(AttributesType::JOB) + race.attributes.magicDefense;
    totalAttributes.physicalAttack = modifiersProcessor.getPhysicalAttackModifier(AttributesType::JOB) + race.attributes.physicalAttack;
    totalAttributes.physicalDefense = modifiersProcessor.getPhysicalDefenseModifier(AttributesType::JOB) + race.attributes.physicalDefense;
}

void AttributesProcessor::setCurrentAttributes() {
    currentAttributes = totalAttributes;
}

void AttributesProcessor::takePhysicalDamage(float damage) {
    float damageReduction = currentAttributes.physicalDefense / (currentAttributes.physicalDefense + 100.0f);
    float realPhysicalDamage = std::max(0.0f, damage * (1.0f - damageReduction));
    currentAttributes.hp -= realPhysicalDamage;

    std::cout << "Damage taken: " << realPhysicalDamage << std::endl;
    std::cout << "Remaining HP: " << currentAttributes.hp << std::endl;
}

void AttributesProcessor::takeMagicDamage(float damage) {
    float damageReduction = currentAttributes.magicDefense / (currentAttributes.magicDefense + 100.0f);
    float realMagicDamage = std::max(0.0f, damage * (1.0f - damageReduction));
    currentAttributes.hp -= realMagicDamage;

    std::cout << "Damage taken: " << realMagicDamage << std::endl;
    std::cout << "Remaining HP: " << currentAttributes.hp << std::endl;
}

void AttributesProcessor::restoreHealth(float amount) {
    currentAttributes.hp = std::min(totalAttributes.hp, currentAttributes.hp + amount);
    std::cout << "Health restored: " << amount << std::endl;
    std::cout << "Current HP: " << currentAttributes.hp << "/" << totalAttributes.hp << std::endl;
}

void AttributesProcessor::levelUp(unsigned int* level) {
    (*level)++;
    updateRaceAttributes(*level);
    calculateTotalAttributes();
    setCurrentAttributes();
    std::cout << "Leveled up! New level: " << *level << std::endl;
}

/**
 * Temporarily boosts the character's attributes for a specified duration.
 * After the timer expires, the attributes are reverted to their original values.
 * This method uses coroutines to handle the delay asynchronously.
 *
 * @param timerSeconds The duration (in seconds) for which the temporary attributes are active.
 * @param tempAttributes The temporary attributes to be applied.
 * @return A coroutine task that completes after the timer expires.
 */
cppcoro::task<> AttributesProcessor::setTemporaryAttributesStatusByTime(int timerSeconds, const Attributes& tempAttributes) {
    temporaryAttributesJob.store(true);
    try {
        Corroutines corroutines;

        Attributes currentAttributesWithoutBuff = currentAttributes;
        calculateSumOfAtrributes(&currentAttributes, tempAttributes);
        co_await corroutines.delay(timerSeconds);
        std::cout << "Temporary attributes expired after " << timerSeconds << " seconds.\n";
        temporaryAttributesJob.store(false);
        currentAttributes = currentAttributesWithoutBuff;
    } catch (const std::exception& e) {
        std::cout << "Error executing coroutine: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown error in coroutine." << std::endl;
    }
    co_return;
}

/**
 * Applies temporary modifiers to the character's attributes for a specified duration.
 * This method delegates the task to the `ModifiersProcessor` class.
 *
 * @param timer The duration (in seconds) for which the modifiers are active.
 * @param attributes The attributes to which the modifiers will be applied.
 */
void AttributesProcessor::setModifiersEffect(int timer, Attributes& attributes) {
    modifiersProcessor.setTemporaryModifiersByTime(timer, attributes);
}

/**
 * Temporarily boosts the character's attributes for a specified duration.
 * After the timer expires, the attributes are reverted to their original values.
 * This method uses coroutines to handle the delay asynchronously.
 *
 * @param timerSeconds The duration (in seconds) for which the temporary attributes are active.
 * @param tempAttributes The temporary attributes to be applied.
 * @return A coroutine task that completes after the timer expires.
 */
void AttributesProcessor::stopTemporaryAttributesJob() {
    temporaryAttributesJob.store(false);
}

Attributes AttributesProcessor::getCurrentAttributes() const {
    return currentAttributes;
}

Attributes AttributesProcessor::getTotalAttributes() const {
    return totalAttributes;
}

/**
 * Calculates and returns the damage of a special physical attack.
 * The damage is based on the character's physical attack stat and a multiplier.
 *
 * @param superAttack The multiplier for the special attack.
 * @return The calculated special physical damage.
 */
float AttributesProcessor::dealSpecialPhysicalDamage(float superAttack) {
    float damage = currentAttributes.physicalAttack + (currentAttributes.physicalAttack * superAttack);
    return damage;
}

/**
 * Calculates and returns the damage of a special magical attack.
 * The damage is based on the character's magic attack stat and a multiplier.
 *
 * @param superAttack The multiplier for the special attack.
 * @return The calculated special magical damage.
 */
float AttributesProcessor::dealSpecialMagicalDamage(float superAttack) {
    float damage = currentAttributes.magicAttack + (currentAttributes.magicAttack * superAttack);
    return damage;
}

void AttributesProcessor::calculateSumOfAtrributes(Attributes* total, const Attributes add) {
    total->hp += add.hp;
    total->magicAttack += add.magicAttack;
    total->magicDefense += add.magicDefense;
    total->physicalAttack += add.physicalAttack;
    total->physicalDefense += add.physicalDefense;
}