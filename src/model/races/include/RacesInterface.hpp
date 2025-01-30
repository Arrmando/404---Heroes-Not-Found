#ifndef RACE_INTERFACE_HPP
#define RACE_INTERFACE_HPP

#include <string>
#include "Race.hpp"

class RaceInterface {
public:

    virtual ~RaceInterface();

    virtual Race getRace() const;
    
    virtual std::string getRaceSpecialTrait() const;

protected:
    virtual void setRaceSpecialTrait();
    
    virtual void setRace(const Race& selectedRace);

};

#endif