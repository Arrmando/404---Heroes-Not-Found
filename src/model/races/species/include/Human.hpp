#ifndef HUMAN_H
#define HUMAN_H

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Human : public Races {
public:
    Human();

protected:
    void setRaceSpecialTrait() override;
};

#endif