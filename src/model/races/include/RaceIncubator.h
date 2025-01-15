#ifndef RACEINCUBATOR_H
#define RACEINCUBATOR_H

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

    static std::unique_ptr<RaceInterface> createRace(Species type);
};

#endif