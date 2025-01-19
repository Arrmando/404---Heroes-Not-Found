#ifndef MONK_H
#define MONK_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Monk : public Jobs {
public:
    Monk();

protected:
    void setJobSpecialTrait() override;
};

#endif