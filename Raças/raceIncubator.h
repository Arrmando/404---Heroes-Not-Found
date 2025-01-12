// raceIncubator.h

#ifndef raceIncubator_H
#define raceIncubator_H

#include "racesinterface.h"
#include "demihumanrace.h"
#include "fairyrace.h"
#include "giantrace.h"
#include "draconicrace.h"
#include "elfrace.h"
#include "humanrace.h"
#include "orcrace.h"
#include <memory>
#include <string>

class raceIncubator {
public:
    enum class RaceType {
        demihuman,
        fairy,
        giant,
        draconic,
        elf,
        human,
        orc,
        undead,

        // Adicione novas raças aqui
    };

    static std::unique_ptr<interfaceRace> createRace(RaceType type) {
        switch(type) {
            case RaceType::demihuman:
                return std::make_unique<demihuman>();
            case RaceType::fairy:
                return std::make_unique<fairy>();
            case RaceType::giant:
                return std::make_unique<giant>();
            case RaceType::draconic:
                return std::make_unique<draconic>();
            case RaceType::elf:
                return std::make_unique<elf>();        
            case RaceType::human:
                return std::make_unique<human>();
            case RaceType::orc:
                return std::make_unique<orc>();
            case RaceType::undead:
                return std::make_unique<undead>();


            default:
                return nullptr;
        }
    }
};

#endif // raceIncubator_H

git config --global user.name "EliasDMS"
git config --global user.email "eliasdaniel_ms@outlook.com.br"