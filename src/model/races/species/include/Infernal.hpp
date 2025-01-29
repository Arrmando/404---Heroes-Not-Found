#ifndef INFERNAL_H
#define INFERNAL_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Infernal : public Races {
public:
    Infernal();

protected:
    void setRaceSpecialTrait() override;
};

#endif
