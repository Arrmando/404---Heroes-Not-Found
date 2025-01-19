#ifndef MODIFIERS_PROCESSOR_H
#define MODIFIERS_PROCESSOR_H

#include "Attributes.hpp"
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>
#include "Corroutines.hpp"
#include <cppcoro/io_service.hpp>
#include "AttibutesType.hpp"

class ModifiersProcessor {
private:
    Attributes raceModifiers;
    Attributes jobModifiers;
    Attributes itensModifiers;
    Attributes temporaryModifiers; // buffs/debuffs
    std::atomic<bool> temporaryModifierJob{false};

public:
    ModifiersProcessor(
        Attributes& raceModifiers,
        Attributes& jobModifiers
    );

    ~ModifiersProcessor();
    
    void updateRaceModifiers(const unsigned int tier);

    void updateJobModifiers(const unsigned int tier);

    cppcoro::task<void> setTemporaryModifiersByTime(int timerSeconds, const Attributes& tempModifier);

        float getHpModifier(const AttributesType type) const;

    float getMagicAttackModifier(const AttributesType type) const;

    float getPhysicalAttackModifier(const AttributesType type);

    float getMagicDefenseModifier(const AttributesType type) const;

    float getPhysicalDefenseModifier(const AttributesType type) const;
    
private:
    void stopTemporaryModifierJob();
};

#endif