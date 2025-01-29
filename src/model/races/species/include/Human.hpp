#ifndef HUMAN_HPP
#define HUMAN_HPP

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