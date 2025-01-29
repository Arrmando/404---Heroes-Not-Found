#ifndef UNDEAD_H
#define UNDEAD_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Undead : public Races {
public:
    Undead();

protected:
    void setRaceSpecialTrait() override;
};

#endif