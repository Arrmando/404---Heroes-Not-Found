#ifndef ELF_H
#define ELF_H

#include "Races.h"
#include "Attributes.h"
#include <iostream>

class Elf : public Races {
public:
    Elf();

protected:
    void setRaceSpecialTrait() override;
};

#endif
