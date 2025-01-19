#ifndef PALADIN_H
#define PALADIN_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Paladin : public Jobs {
public:
    Paladin();

protected:
    void setJobSpecialTrait() override;
};

#endif