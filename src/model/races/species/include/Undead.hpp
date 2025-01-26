#ifndef UNDEAD_HPP
#define UNDEAD_HPP

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Undead : public Races {
public:
    Undead();

protected:
    void setRaceSpecialTrait() override;
};

#endif