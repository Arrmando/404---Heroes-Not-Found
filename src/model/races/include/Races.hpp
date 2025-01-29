#ifndef RACES_H
#define RACES_H

#include <iostream>
#include <string>
#include <memory>
#include "../model/races/RacesInterface.hpp"

class Races : public RaceInterface {
public:
    Race race;

    Races() = default;

    Race getRace() const;
    
protected:

    void setRace(const Race& selectedRace);

};

#endif