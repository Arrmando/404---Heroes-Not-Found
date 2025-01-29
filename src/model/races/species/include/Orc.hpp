#ifndef ORC_HPP
#define ORC_HPP

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
