#include "Attributes.h"
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <iostream>
#include "Corroutines.hpp"
#include <cppcoro/io_service.hpp>
#include "AttibutesType.hpp"
#include <functional>

class ModifiersProcessor {
private:
    std::reference_wrapper<Attributes> raceModifiers;
    std::reference_wrapper<Attributes> jobModifiers;
    Attributes itensModifiers;
    Attributes temporaryModifiers; // buffs/debuffs
    std::atomic<bool> temporaryModifierJob{false};

public:
    ModifiersProcessor(
        Attributes& raceModifiers,
        Attributes& jobModifiers
    ) : raceModifiers(raceModifiers), jobModifiers(jobModifiers) {}

    ~ModifiersProcessor(){
        if(temporaryModifierJob.load())
            stopTemporaryModifierJob();
    }
    
    void updateRaceModifiers(const unsigned int tier) {
        raceModifiers.get().hp = tier;
        raceModifiers.get().magicAttack *= tier;
        raceModifiers.get().magicDefense *= tier;
        raceModifiers.get().physicalAttack *= tier;
        raceModifiers.get().physicalDefense *= tier;
    }

    void updateJobModifiers(const unsigned int tier) {
        jobModifiers.get().hp *= tier;
        jobModifiers.get().magicAttack *= tier;
        jobModifiers.get().magicDefense *= tier;
        jobModifiers.get().physicalAttack *= tier;
        jobModifiers.get().physicalDefense *= tier;
    }

    cppcoro::task<void> setTemporaryModifiersByTime(int timerSeconds, const Attributes& tempModifier) {
        temporaryModifierJob.store(true);
        temporaryModifiers = tempModifier;
        try {
            Corroutines corroutines;
        
            if(!temporaryModifierJob.load())
                co_return

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

    float getHpModifier(const AttributesType type) const { 
        switch (type){
            case AttributesType::RACE:
                return raceModifiers.get().hp;
            case AttributesType::JOB:
                return jobModifiers.get().hp;
            default:
                return 0.0f;
        }
    }

    float getMagicAttackModifier(const AttributesType type) const {        
        switch (type){
            case AttributesType::RACE:
                return raceModifiers.get().magicAttack;
            case AttributesType::JOB:
                return jobModifiers.get().magicAttack;
            default:
                return 0.0f;
        }; 
    }

    float getPhysicalAttackModifier(const AttributesType type) const {         
        switch (type){
            case AttributesType::RACE:
                return raceModifiers.get().physicalAttack;
            case AttributesType::JOB:
                return jobModifiers.get().physicalAttack;
            default:
                return 0.0f;
        }; 
    }

    float getMagicDefenseModifier(const AttributesType type) const {         
        switch (type){
            case AttributesType::RACE:
                return raceModifiers.get().magicDefense;
            case AttributesType::JOB:
                return jobModifiers.get().magicDefense;
            default:
                return 0.0f;
        }; 
    }

    float getPhysicalDefenseModifier(const AttributesType type) const {         
        switch (type){
            case AttributesType::RACE:
                return raceModifiers.get().physicalDefense;
            case AttributesType::JOB:
                return jobModifiers.get().physicalDefense;
            default:
                return 0.0f;
        }; 
    }

private:
    void stopTemporaryModifierJob() {
        temporaryModifierJob.store(false);
    }
};