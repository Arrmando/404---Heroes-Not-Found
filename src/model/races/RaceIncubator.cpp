#include "RacesInterface.hpp"
#include "Human.hpp"
#include "Elf.hpp"
#include "Demihuman.hpp"
#include "Fairy.hpp"
#include "Draconic.hpp"
#include "Giant.hpp"
#include "Races.hpp"
#include "Orc.hpp"
#include "Undead.hpp"
#include "Infernal.hpp"
#include "Vampire.hpp"
#include <memory>
#include <string>

class RaceIncubator {
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
            case Species::INFERNAL:
                return std::make_unique<Infernal>();
            case Species::VAMPIRE:
                return std::make_unique<Vampire>();
            default:
                throw std::invalid_argument("Invalid species type provided to RaceIncubator.");
        }
    }
};