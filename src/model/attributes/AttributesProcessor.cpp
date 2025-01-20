#include <iostream>
#include <algorithm>
#include "Attributes.hpp"
#include "Race.hpp"
#include "Job.hpp"
#include "ModifiersProcessor.hpp"
#include <memory>
#include "AttibutesType.hpp"
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include "Corroutines.hpp"
#include <cppcoro/io_service.hpp>

class AttributesProcessor {
private:
    Race race;
    Job job;
    Attributes totalAttributes;
    Attributes currentAttributes;
    ModifiersProcessor modifiersProcessor;
    std::atomic<bool> temporaryAttributesJob{false};


public:
    AttributesProcessor(
        Race& race_,
        Job& job_
    ) : race(race_), job(job_), modifiersProcessor(std::ref(race.modifiers),std::ref(job.modifiers)) {}

    void updateRaceAttributes(const unsigned int level) {
        race.attributes.hp += race.attributes.hp * modifiersProcessor.getHpModifier(AttributesType::RACE)*level;
        race.attributes.magicAttack += race.attributes.magicAttack * modifiersProcessor.getMagicAttackModifier(AttributesType::RACE)*level;
        race.attributes.magicDefense += race.attributes.magicDefense * modifiersProcessor.getMagicDefenseModifier(AttributesType::RACE)*level;
        race.attributes.physicalAttack += race.attributes.physicalAttack * modifiersProcessor.getPhysicalAttackModifier(AttributesType::RACE)*level;
        race.attributes.physicalDefense += race.attributes.physicalDefense * modifiersProcessor.getPhysicalDefenseModifier(AttributesType::RACE)*level;
    }

    void updateJobAttributes(const unsigned int level) {
        job.attributes.hp += race.attributes.hp * modifiersProcessor.getHpModifier(AttributesType::JOB)*level;
        job.attributes.magicAttack += race.attributes.magicAttack * modifiersProcessor.getMagicAttackModifier(AttributesType::JOB)*level;
        job.attributes.magicDefense += race.attributes.magicDefense * modifiersProcessor.getMagicDefenseModifier(AttributesType::JOB)*level;
        job.attributes.physicalAttack += race.attributes.physicalAttack * modifiersProcessor.getPhysicalAttackModifier(AttributesType::JOB)*level;
        job.attributes.physicalDefense += race.attributes.physicalDefense * modifiersProcessor.getPhysicalDefenseModifier(AttributesType::JOB)*level;
    }

    void calculateTotalAttributes() {
        totalAttributes.hp = job.attributes.hp + race.attributes.hp;
        totalAttributes.magicAttack = job.attributes.magicAttack + race.attributes.magicAttack;
        totalAttributes.magicDefense = job.attributes.magicDefense + race.attributes.magicDefense;
        totalAttributes.physicalAttack = job.attributes.physicalAttack + race.attributes.physicalAttack;
        totalAttributes.physicalDefense = job.attributes.physicalDefense + race.attributes.physicalDefense;
    }

    void setCurrentAttributes() {
        currentAttributes = totalAttributes;
    }
   
    }
 
    void takePhysicalDamage(float damage) {
        float damageReduction = currentAttributes.physicalDefense / (currentAttributes.physicalDefense + 100.0f); 
        float realPhysicalDamage = std::max(0.0f, damage * (1.0f - damageReduction));
        currentAttributes.hp -= realPhysicalDamage;
    
        std::cout << "Damage taken: " << realPhysicalDamage << std::endl;
        std::cout << "Remaining HP: " << currentAttributes.hp << std::endl;
    }

    void takeMagicDamage(float damage) {
        float damageReduction = currentAttributes.magicDefense / (currentAttributes.magicDefense + 100.0f); 
        float realMagicDamage = std::max(0.0f, damage * (1.0f - damageReduction));
        currentAttributes.hp -= realMagicDamage;
    
        std::cout << "Damage taken: " << realMagicDamage << std::endl;
        std::cout << "Remaining HP: " << currentAttributes.hp << std::endl;
    }

    void restoreHealth(float amount) {
        currentAttributes.hp = std::min(totalAttributes.hp, currentAttributes.hp + amount);
        std::cout << "Health restored: " << amount << std::endl;
        std::cout << "Current HP: " << currentAttributes.hp << "/" << totalAttributes.hp << std::endl;
    }

    void levelUp(unsigned int* level) {
        level++;
        updateRaceAttributes(*level);
        updateJobAttributes(*level);
        calculateTotalAttributes();
        setCurrentAttributes();
        std::cout << "Leveled up! New level: " << level << std::endl;
    }

    cppcoro::task<void> setTemporaryAttributesStatusByTime(int timerSeconds, const Attributes& tempAttributes) {
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

    Attributes getCurrentAttributes() const { 
        return currentAttributes;
    }
    
    Attributes getTotalAttributes() const { 
        return totalAttributes;
    }
    
     float dealSpecialPhysicalDamage(float superAttack) {
        float damage = currentAttributes.physicalAttack + (currentAttributes.physicalAttack * superAttack);
        return damage;   
    }
    float dealSpecialMagicalDamage(float superAttack) {
        float damage = currentAttributes.magicAttack + (correntAttributes.magicAttack * superAttack);
        return damage;

private:
    void stopTemporaryAttributesJob() {
        temporaryAttributesJob.store(false);
    }

    void calculateSumOfAtrributes(Attributes* total, const Attributes add) {
        total->hp += add.hp;
        total->magicAttack += add.magicAttack;
        total->magicDefense += add.magicDefense;
        total->physicalAttack += add.physicalAttack;
        total->physicalDefense += add.physicalDefense;
    }
};