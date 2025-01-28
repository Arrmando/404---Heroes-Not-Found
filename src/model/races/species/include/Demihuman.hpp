#ifndef DEMIHUMAN_HPP
#define DEMIHUMAN_HPP

#include "Races.hpp"

class Demihuman : public Races {
public:
    Demihuman();

protected:
    void setRaceSpecialTrait() override;
};

#endif