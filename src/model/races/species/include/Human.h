#ifndef HUMAN_H
#define HUMAN_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Human : public Races {
public:
    Human();

protected:
    void setRaceSpecialTrait() override;
};

#endif