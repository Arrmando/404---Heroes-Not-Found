#ifndef ATTRIBUTES_PROCESSOR_H
#define ATTRIBUTES_PROCESSOR_H

#include <iostream>
#include <algorithm>
#include <memory>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <cppcoro/io_service.hpp>
#include "../utils/include/Attributes.hpp"
#include "../utils/include/Race.hpp"
#include "../utils/include/Job.hpp"
#include "../model/modifiers/include/ModifiersProcessor.hpp"
#include "../utils/include/AttibutesType.hpp"
#include "../utils/include/Corroutines.hpp"

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
    );

    void updateRaceAttributes(const unsigned int level);

    void updateJobAttributes(const unsigned int level);

    void calculateTotalAttributes();

    void setCurrentAttributes();

    float takePhysicalDamage(float damage);

    float takeMagicDamage(float damage);

    void restoreHealth(float amount);

    void levelUp(unsigned int* level);

    cppcoro::task<void> setTemporaryAttributesStatusByTime(int timerSeconds, const Attributes& tempAttributes);

    void setModifiersEffect(int timer, Attributes& attributes);
    
    Attributes getCurrentAttributes();
    
    Attributes getTotalAttributes();

    float dealSpecialPhysicalDamage(float superAttack);

    float dealSpecialMagicalDamage(float superAttack);
    
private:

    void stopTemporaryAttributesJob();

    void calculateSumOfAtrributes(Attributes* total, const Attributes add);
};

#endif