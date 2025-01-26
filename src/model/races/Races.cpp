#include <iostream>
#include <string>
#include <memory>
#include "RacesInterface.hpp"

class Races : public RaceInterface {
public:
    Race race;

    Races() = default;

    Race getRace() const {
        return race;
    }
    
protected:

    void setRace(const Race& selectedRace) {
        race = selectedRace;
    };

};