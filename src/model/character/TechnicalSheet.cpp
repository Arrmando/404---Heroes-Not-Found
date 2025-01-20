#include <string>
#include <memory>
#include "RacesInterface.hpp"
#include "JobsInterface.hpp"
#include "RaceIncubator.hpp"
#include "JobIncubator.hpp"
#include "AttributesProcessor.hpp"

class TechnicalSheet {
private:
    std::unique_ptr<AttributesProcessor> attributesProcessor;
    std::unique_ptr<JobInterface> job;
    std::unique_ptr<RaceInterface> race;
    float totalExp, currentExp;
    

public:
    int level;
    float dracmas;
    std::string name;
    Species species;
    Classes classes;

    TechnicalSheet(
        int level,
        std::string name,
        Species species_,
        Classes classes_
    ): name(name), level(level), species(species_), classes(classes_) {
        race = RaceIncubator::createRace(species);
        job = JobIncubator::createJob(classes);
        attributesProcessor = std::make_unique<AttributesProcessor>(race->getRace(), job->getJob());
    }

    void useJobSkill() {
        switch(classes){
            //TODO 
        }
    }

    void physicalAttack() {
        //TODO
    }

    void magicalAttack() {
        //TODO
    }

    void showCharacterAttributes() {
        //TODO
    }

    void receiveMagicalDamage(float damage) {
        attributesProcessor->takeMagicDamage(damage);
    }
    
    void receivePhysicalDamage(float damage) {
        attributesProcessor->takePhysicalDamage(damage);
    }

    void applyStatusEffect(int timer, Attributes attributes) {
        attributesProcessor->setTemporaryAttributesStatusByTime(timer, attributes);
    }

    void aplyModifiersEffect(int timer, Attributes attributes) {
        attributesProcessor->setModifiersEffect(timer, attributes);
    }

    void increaseDracmas(float amount) {
        dracmas += amount;
    }

    void reduceIncrease(float amount) {
        dracmas -= amount;
    }

    void increaseExp(float expReceived) {
        currentExp += expReceived;

        while (currentExp >= totalExp) {
            currentExp -= totalExp;
            updateTotalExp();
            level++;       
        }
    }

private:
    void updateTotalExp() {
        totalExp *= 1.5f;
    }
};