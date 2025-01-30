#ifndef GIANT_HPP
#define GIANT_HPP

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Giant : public Races {
public:
    Giant();

protected:
    void setRaceSpecialTrait() override;
};

#endif
