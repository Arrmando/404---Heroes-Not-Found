#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Vampire : public Races {
public:
    Vampire();

protected:
    void setRaceSpecialTrait() override;
};

#endif
