#ifndef TECHNICAL_SHEET_HPP
#define TECHNICAL_SHEET_HPP

#include <string>
#include <memory>
#include "../races/RacesInterface.hpp"
#include "../jobs/JobsInterface.hpp"
#include "../races/include/RaceIncubator.hpp"
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
    );

    void useJobSkill();

    void physicalAttack();

    void magicalAttack();

    void showCharacterAttributes();

    void receiveMagicalDamage(float damage);
    
    void receivePhysicalDamage(float damage);

    void applyStatusEffect(int timer, Attributes attributes);

    void aplyModifiersEffect(int timer, Attributes attributes);

    void increaseDracmas(float amount);

    void reduceIncrease(float amount);

    void increaseExp(float expReceived);

private:
    void updateTotalExp();
};

#endif // !TECHNICAL_SHEET_HPP