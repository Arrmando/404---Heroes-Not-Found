#ifndef JOB_INCUBATOR_H
#define JOB_INCUBATOR_H

#include <memory>
#include <string>
#include "../utils/include/Classes.hpp"
#include "../model/jobs/JobsInterface.hpp"
#include "../model/jobs/classes/include/Barbarian.hpp"
#include "../model/jobs/classes/include/Bard.hpp"
#include "../model/jobs/classes/include/Druid.hpp"
#include "../model/jobs/classes/include/Mage.hpp"
#include "../model/jobs/classes/include/Monk.hpp"
#include "../model/jobs/classes/include/Necromancer.hpp"
#include "../model/jobs/classes/include/Paladin.hpp"
#include "../model/jobs/classes/include/Ranger.hpp"
#include "../model/jobs/classes/include/Rogue.hpp"
#include "../model/jobs/classes/include/Sorcerer.hpp"
#include "../model/jobs/classes/include/Warrior.hpp"

class JobIncubator {
public:

    static std::unique_ptr<JobInterface> createJob(Classes type);
    
};

#endif