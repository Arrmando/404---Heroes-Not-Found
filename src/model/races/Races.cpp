#ifndef RACES_H
#define RACES_H

#include <iostream>
#include <string>
#include <memory>
#include "RacesInterface.hpp"

class Races : public RaceInterface {
public:
    Races() = default;

    Race getRace() const {
        return race;
    }
    
protected:

    void setRace(const Race& selectedRace) {
        race = selectedRace;
    };

};

#endif 
