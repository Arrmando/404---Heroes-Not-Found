#ifndef MODIFIERS_PROCESSOR_HPP
#define MODIFIERS_PROCESSOR_HPP

#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>
#include <cppcoro/io_service.hpp>
#include <functional>
#include "Attributes.hpp"
#include "Corroutines.hpp"
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

    float getPhysicalAttackModifier(const AttributesType type) const;

    float getMagicDefenseModifier(const AttributesType type) const;

    float getPhysicalDefenseModifier(const AttributesType type) const;
    
private:
    void stopTemporaryModifierJob();
};

#endif