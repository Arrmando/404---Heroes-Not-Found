#ifndef WARRIOR_h
#define WARRIOR_h

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Warrior : public Jobs {
public:
    Warrior();

protected:
    void setJobSpecialTrait() override;
};

#endif