#ifndef FAIRY_H
#define FAIRY_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Fairy : public Races {
public:
    Fairy();

protected:
    void setRaceSpecialTrait() override;
};

#endif
