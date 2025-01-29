#ifndef HUMAN_H
#define HUMAN_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Human : public Races {
public:
    Human();

protected:
    void setRaceSpecialTrait() override;
};

#endif