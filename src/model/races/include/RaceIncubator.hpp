#ifndef RACEINCUBATOR_HPP
#define RACEINCUBATOR_HPP

#include <memory>
#include <string>
#include "../model/races/RacesInterface.hpp"
#include "../model/races/species/include/Human.hpp"
#include "../model/races/species/include/Elf.hpp"
#include "../model/races/species/include/Demihuman.hpp"
#include "../model/races/species/include/Infernal.hpp"
#include "../model/races/species/include/Vampire.hpp"
#include "../model/races/species/include/Fairy.hpp"
#include "../model/races/species/include/Draconic.hpp"
#include "../model/races/species/include/Giant.hpp"
#include "../model/races/include/Races.hpp"
#include "../model/races/species/include/Orc.hpp"
#include "../model/races/species/include/Undead.hpp"

class RaceIncubator {
public:

    static std::unique_ptr<RaceInterface> createRace(Species type);
};

#endif