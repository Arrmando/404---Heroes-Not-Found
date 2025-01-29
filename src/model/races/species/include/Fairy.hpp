#ifndef FAIRY_HPP
#define FAIRY_HPP

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Fairy : public Races {
public:
    Fairy();

protected:
    void setRaceSpecialTrait() override;
};

#endif
