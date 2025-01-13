#ifndef RACE_INTERFACE_H
#define RACE_INTERFACE_H

#include "utils/include/Race.h"
#include <string>

class RaceInterface {
public:
    Race race;

    virtual ~RaceInterface() = default;

    virtual Race getRace() const = 0;
    
    virtual std::string getRaceSpecialTrait() const = 0;

protected:
    virtual void setRaceSpecialTrait() = 0;
    
    virtual void setRace(const Race& selectedRace) = 0;

};

#endif