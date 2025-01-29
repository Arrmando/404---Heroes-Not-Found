#ifndef GIANT_H
#define GIANT_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Giant : public Races {
public:
    Giant();

protected:
    void setRaceSpecialTrait() override;
};

#endif
