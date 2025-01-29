#ifndef DRACONIC_HPP
#define DRACONIC_HPP

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Draconic : public Races {
public:
    Draconic();

protected:
    void setRaceSpecialTrait() override;
};

#endif