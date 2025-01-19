#ifndef MAGE_H
#define MAGE_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Mage : public Jobs {
public:
    Mage();

protected:
    void setJobSpecialTrait() override;
};

#endif