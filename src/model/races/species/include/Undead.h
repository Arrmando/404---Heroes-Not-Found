#ifndef UNDEAD_H
#define UNDEAD_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Undead : public Races {
public:
    Undead();

protected:
    void setRaceSpecialTrait() override;
};

#endif