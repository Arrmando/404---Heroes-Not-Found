#ifndef DEMIHUMAN_H
#define DEMIHUMAN_H

#include "Races.hpp"

class Demihuman : public Races {
public:
    Demihuman();

protected:
    void setRaceSpecialTrait() override;
};

#endif