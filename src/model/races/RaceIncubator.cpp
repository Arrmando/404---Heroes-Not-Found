#include <memory>
#include <string>
#include "../../model/races/include/RacesInterface.hpp"
#include "../../model/races/species/include/Human.hpp"
#include "../../model/races/species/include/Elf.hpp"
#include "../../model/races/species/include/Demihuman.hpp"
#include "../../model/races/species/include/Infernal.hpp"
#include "../../model/races/species/include/Vampire.hpp"
#include "../../model/races/species/include/Fairy.hpp"
#include "../../model/races/species/include/Draconic.hpp"
#include "../../model/races/species/include/Giant.hpp"
#include "../../model/races/include/Races.hpp"
#include "../../model/races/species/include/Orc.hpp"
#include "../../model/races/species/include/Undead.hpp"
#include "RaceIncubator.hpp"

/**
 * Creates a new race object based on the provided species type.
 * This method uses a factory pattern to instantiate the appropriate race class.
 *
 * @param type The type of species to create (from the Species enum).
 * @return A unique_ptr to the created race object.
 * @throws std::invalid_argument If an invalid species type is provided.
 */
std::unique_ptr<RaceInterface> RaceIncubator::createRace(Species type) {
    switch (type) {
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