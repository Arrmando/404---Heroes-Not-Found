#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>
#include <cppcoro/io_service.hpp>
#include <functional>
#include "../../../utils/include/Attributes.hpp"
#include "../../../utils/include/Corroutines.hpp"
#include "../../../utils/include/AttibutesType.hpp"
#include "ModifiersProcessor.hpp"

/**
 * Constructor for the ModifiersProcessor class.
 * Initializes the race and job modifiers using references to external Attributes objects.
 *
 * @param raceModifiers Reference to the race-specific modifiers.
 * @param jobModifiers Reference to the job-specific modifiers.
 */
ModifiersProcessor::ModifiersProcessor(
    Attributes& raceModifiers,
    Attributes& jobModifiers
) : raceModifiers(raceModifiers), jobModifiers(jobModifiers) {}

/**
 * Destructor for the ModifiersProcessor class.
 * Ensures that any ongoing temporary modifier job is stopped.
 */
ModifiersProcessor::~ModifiersProcessor() {
    if (temporaryModifierJob.load())
        stopTemporaryModifierJob();
}

/**
 * Updates the race modifiers based on the provided tier.
 * Scales the race attributes by the tier value.
 *
 * @param tier The tier value used to scale the race modifiers.
 */
void ModifiersProcessor::updateRaceModifiers(const unsigned int tier) {
    raceModifiers.hp = tier;
    raceModifiers.magicAttack *= tier;
    raceModifiers.magicDefense *= tier;
    raceModifiers.physicalAttack *= tier;
    raceModifiers.physicalDefense *= tier;
}

/**
 * Updates the job modifiers based on the provided tier.
 * Scales the job attributes by the tier value.
 *
 * @param tier The tier value used to scale the job modifiers.
 */
void ModifiersProcessor::updateJobModifiers(const unsigned int tier) {
    jobModifiers.hp *= tier;
    jobModifiers.magicAttack *= tier;
    jobModifiers.magicDefense *= tier;
    jobModifiers.physicalAttack *= tier;
    jobModifiers.physicalDefense *= tier;
}

/**
 * Applies temporary modifiers for a specified duration.
 * Uses coroutines to handle the delay asynchronously.
 *
 * @param timerSeconds The duration (in seconds) for which the temporary modifiers are active.
 * @param tempModifier The temporary modifiers to be applied.
 * @return A coroutine task that completes after the timer expires.
 */
cppcoro::task<void> ModifiersProcessor::setTemporaryModifiersByTime(int timerSeconds, const Attributes& tempModifier) {
    temporaryModifierJob.store(true);
    temporaryModifiers = tempModifier;
    try {
        Corroutines corroutines;

        if (!temporaryModifierJob.load())
            co_return;

        co_await corroutines.delay(timerSeconds);
        std::cout << "Temporary modifiers expired after " << timerSeconds << " seconds.\n";
        temporaryModifierJob.store(false);

        temporaryModifiers = {};

    } catch (const std::exception& e) {
        std::cout << "Error executing coroutine: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown error in coroutine." << std::endl;
    }
    co_return;
}

float ModifiersProcessor::getHpModifier(const AttributesType type) const {
    switch (type) {
        case AttributesType::RACE:
            return raceModifiers.hp;
        case AttributesType::JOB:
            return jobModifiers.hp;
        default:
            return 0.0f;
    }
}

float ModifiersProcessor::getMagicAttackModifier(const AttributesType type) const {
    switch (type) {
        case AttributesType::RACE:
            return raceModifiers.magicAttack;
        case AttributesType::JOB:
            return jobModifiers.magicAttack;
        default:
            return 0.0f;
    }
}

float ModifiersProcessor::getPhysicalAttackModifier(const AttributesType type) const {
    switch (type) {
        case AttributesType::RACE:
            return raceModifiers.physicalAttack;
        case AttributesType::JOB:
            return jobModifiers.physicalAttack;
        default:
            return 0.0f;
    }
}

float ModifiersProcessor::getMagicDefenseModifier(const AttributesType type) const {
    switch (type) {
        case AttributesType::RACE:
            return raceModifiers.magicDefense;
        case AttributesType::JOB:
            return jobModifiers.magicDefense;
        default:
            return 0.0f;
    }
}

float ModifiersProcessor::getPhysicalDefenseModifier(const AttributesType type) const {
    switch (type) {
        case AttributesType::RACE:
            return raceModifiers.physicalDefense;
        case AttributesType::JOB:
            return jobModifiers.physicalDefense;
        default:
            return 0.0f;
    }
}

/**
 * Stops the temporary modifier job.
 * This method is private and can only be called internally.
 */
void ModifiersProcessor::stopTemporaryModifierJob() {
    temporaryModifierJob.store(false);
}