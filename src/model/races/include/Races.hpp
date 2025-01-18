#ifndef RACES_H
#define RACES_H

#include <iostream>
#include <string>
#include <memory>
#include "RacesInterface.h"

class Races : public RaceInterface {
public:
    Races() = default;

    Race getRace() const;
    
protected:

    void setRace(const Race& selectedRace);

};

#endif