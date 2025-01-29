#ifndef ORC_H
#define ORC_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Orc : public Races {
public:
    Orc();

protected:
    void setRaceSpecialTrait() override;
};

#endif
