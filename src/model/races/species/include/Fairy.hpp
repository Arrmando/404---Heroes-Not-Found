#ifndef FAIRY_H
#define FAIRY_H

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Fairy : public Races {
public:
    Fairy();

protected:
    void setRaceSpecialTrait() override;
};

#endif
