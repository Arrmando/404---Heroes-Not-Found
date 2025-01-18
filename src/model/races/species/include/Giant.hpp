#ifndef GIANT_H
#define GIANT_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Giant : public Races {
public:
    Giant();

protected:
    void setRaceSpecialTrait() override;
};

#endif
