#ifndef DEMIHUMAN_H
#define DEMIHUMAN_H

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
class Demihuman : public Races {
public:
    Demihuman();

protected:
    void setRaceSpecialTrait() override;
};

#endif