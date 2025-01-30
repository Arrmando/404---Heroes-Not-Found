#include <iostream>
#include <string>
#include <memory>
#include "../../model/races/include/RacesInterface.hpp"
#include "Races.hpp" 

Races::Races() = default;

Race Races::getRace() const {
    return race;
}

void Races::setRace(const Race& selectedRace) {
    race = selectedRace;
}