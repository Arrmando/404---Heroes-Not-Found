#ifndef JOB_INCUBATOR_H
#define JOB_INCUBATOR_H

#include <memory>
#include <string>
#include "Classes.hpp"
#include "JobsInterface.hpp"
#include "Barbarian.hpp"
#include "Bard.hpp"
#include "Druid.hpp"
#include "Mage.hpp"
#include "Monk.hpp"
#include "Necromancer.hpp"
#include "Paladin.hpp"
#include "Ranger.hpp"
#include "Rogue.hpp"
#include "Sorcerer.hpp"
#include "Warrior.hpp"

class JobIncubator {
public:

    static std::unique_ptr<JobInterface> createJob(Classes type);
    
};

#endif