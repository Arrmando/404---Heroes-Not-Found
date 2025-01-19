#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Barbarian : public Jobs {
public:
    Barbarian();

protected:
    void setJobSpecialTrait() override;
};

#endif