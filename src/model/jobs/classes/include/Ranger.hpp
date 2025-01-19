#ifndef RANGER_H
#define RANGER_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Ranger : public Jobs {
public:
    Ranger();

protected:
    void setJobSpecialTrait() override;
};

#endif