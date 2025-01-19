#ifndef ROGUE_h
#define ROGUE_h

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Rogue : public Jobs {
public:
    Rogue();

protected:
    void setJobSpecialTrait() override;
};

#endif