#ifndef DRACONIC_H
#define DRACONIC_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Draconic : public Races {
public:
    Draconic();

protected:
    void setRaceSpecialTrait() override;
};

#endif