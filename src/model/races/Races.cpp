#include <iostream>
#include <string>
#include <memory>
#include "../model/races/RacesInterface.hpp"

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