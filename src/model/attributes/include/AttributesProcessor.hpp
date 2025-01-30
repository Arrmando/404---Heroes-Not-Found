#ifndef ATTRIBUTES_PROCESSOR_HPP
#define ATTRIBUTES_PROCESSOR_HPP

#include <iostream>
#include <algorithm>
#include <memory>
#include <cppcoro/task.hpp>
#include <cppcoro/sync_wait.hpp>
#include <chrono>
#include <thread>
#include <atomic>
#include <cppcoro/io_service.hpp>
#include "Attributes.hpp"
#include "Race.hpp"
#include "Job.hpp"
#include "AttibutesType.hpp"
#include "Corroutines.hpp"
#include "ModifiersProcessor.hpp"

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
        Race race_,
        Job job_
    );

    void updateRaceAttributes(const unsigned int level);

    void updateJobAttributes(const unsigned int level);

    void calculateTotalAttributes();

    void setCurrentAttributes();

    void takePhysicalDamage(float damage);

    void takeMagicDamage(float damage);

    void restoreHealth(float amount);

    void levelUp(unsigned int* level);

    cppcoro::task<void> setTemporaryAttributesStatusByTime(int timerSeconds, const Attributes& tempAttributes);

    void setModifiersEffect(int timer, Attributes& attributes);
    
    Attributes getCurrentAttributes() const;
    
    Attributes getTotalAttributes() const;

    float dealSpecialPhysicalDamage(float superAttack);

    float dealSpecialMagicalDamage(float superAttack);
    
private:

    void stopTemporaryAttributesJob();

    void calculateSumOfAtrributes(Attributes* total, const Attributes add);
};

#endif