#include <string>
#include "../../../../utils/include/Race.hpp"
#include "RacesInterface.hpp"

RaceInterface::~RaceInterface() = default;

Race RaceInterface::getRace() const {}

std::string RaceInterface::getRaceSpecialTrait() const {}

void RaceInterface::setRaceSpecialTrait() {}

void RaceInterface::setRace(const Race& selectedRace) {}