#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Vampire : public Races {
public:
    Vampire();

protected:
    void setRaceSpecialTrait() override;
};

#endif
