#ifndef ATTRIBUTES_PROCESSOR_H
#define ATTRIBUTES_PROCESSOR_H

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
    
private:

    void stopTemporaryAttributesJob();

    void calculateSumOfAtrributes(Attributes* total, const Attributes add);
};

#endif