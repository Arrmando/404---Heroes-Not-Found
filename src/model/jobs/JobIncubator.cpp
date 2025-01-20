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

    static std::unique_ptr<JobInterface> createJob(Classes type) {
        switch(type) {
            case Classes::BARBARIAN:
                return std::make_unique<Barbarian>();
            case Classes::BARD:
                return std::make_unique<Bard>();
            case Classes::DRUID:
                return std::make_unique<Druid>();
            case Classes::MAGE:
                return std::make_unique<Monk>();
            case Classes::NECROMANCER:
                return std::make_unique<Necromancer>();        
            case Classes::PALADIN:
                return std::make_unique<Paladin>();
            case Classes::RANGER:
                return std::make_unique<Ranger>();
            case Classes::ROGUE:
                return std::make_unique<Rogue>();
            case Classes::SORCERER:
                return std::make_unique<Sorcerer>();
            case Classes::WARRIOR:
                return std::make_unique<Warrior>();                
            default:
                throw std::invalid_argument("Invalid classes type provided.");
        }
    }
};