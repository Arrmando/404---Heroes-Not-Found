#ifndef RACES_HPP
#define RACES_HPP

#include <iostream>
#include <string>
#include <memory>
#include "RacesInterface.hpp"

class Races : public RaceInterface {
public:
    Race race;

    Races();

    Race getRace() const;
    
protected:

    void setRace(const Race& selectedRace);

};

#endif