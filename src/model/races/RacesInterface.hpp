#ifndef RACE_INTERFACE_HPP
#define RACE_INTERFACE_HPP

#include "../utils/include/Race.hpp"
#include <string>

class RaceInterface {
public:

    virtual ~RaceInterface() = default;

    virtual Race getRace() const = 0;
    
    virtual std::string getRaceSpecialTrait() const = 0;

protected:
    virtual void setRaceSpecialTrait() = 0;
    
    virtual void setRace(const Race& selectedRace) = 0;

};

#endif