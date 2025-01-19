#ifndef CLERIC_H
#define CLERIC_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Cleric : public Jobs {
public:
    Cleric();

protected:
    void setJobSpecialTrait() override;
};

#endif