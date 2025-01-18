#ifndef ORC_H
#define ORC_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Orc : public Races {
public:
    Orc();

protected:
    void setRaceSpecialTrait() override;
};

#endif
