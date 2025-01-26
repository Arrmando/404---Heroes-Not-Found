#ifndef RACEINCUBATOR_HPP
#define RACEINCUBATOR_HPP

#include "RacesInterface.hpp"
#include "Human.hpp"
#include "Elf.hpp"
#include "Demihuman.hpp"
#include "Infernal.hpp"
#include "Vampire.hpp"
#include "Fairy.hpp"
#include "Draconic.hpp"
#include "Giant.hpp"
#include "Races.hpp"
#include "Orc.hpp"
#include "Undead.hpp"
#include <memory>
#include <string>

class RaceIncubator {
public:

    static std::unique_ptr<RaceInterface> createRace(Species type);
};

#endif