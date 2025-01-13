#include "RacesInterface.h"
#include "Human.h"
#include "Elf.h"
#include "Demihuman.h"
#include "Fairy.h"
#include "Draconic.h"
#include "Giant.h"
#include "Races.h"
#include "Orc.h"
#include "Undead.h"
#include <memory>
#include <string>

class raceIncubator {
public:

    static std::unique_ptr<RaceInterface> createRace(Species type) {
        switch(type) {
            case Species::DEMIHUMAN:
                return std::make_unique<Demihuman>();
            case Species::FAIRY:
                return std::make_unique<Fairy>();
            case Species::GIANT:
                return std::make_unique<Giant>();
            case Species::DRACONIC:
                return std::make_unique<Draconic>();
            case Species::ELF:
                return std::make_unique<Elf>();        
            case Species::HUMAN:
                return std::make_unique<Human>();
            case Species::ORC:
                return std::make_unique<Orc>();
            case Species::UNDEAD:
                return std::make_unique<Undead>();
            default:
                throw std::invalid_argument("Invalid species type provided to RaceIncubator.");
        }
    }
};