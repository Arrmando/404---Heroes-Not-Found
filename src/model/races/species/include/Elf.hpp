#ifndef ELF_H
#define ELF_H

#include "Races.hpp"
#include "Attributes.hpp"
#include <iostream>

class Elf : public Races {
public:
    Elf();

protected:
    void setRaceSpecialTrait() override;
};

#endif
