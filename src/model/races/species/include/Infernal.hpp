#ifndef INFERNAL_HPP
#define INFERNAL_HPP

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
