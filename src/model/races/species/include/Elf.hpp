#ifndef ELF_HPP
#define ELF_HPP

#include "Races.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>

class Elf : public Races {
public:
    Elf();

protected:
    void setRaceSpecialTrait() override;
};

#endif
