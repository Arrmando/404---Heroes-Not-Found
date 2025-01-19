#ifndef ORC_H
#define ORC_H

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Orc : public Races {
public:
    Orc();

protected:
    void setRaceSpecialTrait() override;
};

#endif
