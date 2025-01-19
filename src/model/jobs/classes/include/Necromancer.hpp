#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Necromancer : public Jobs {
public:
    Necromancer();

protected:
    void setJobSpecialTrait() override;
};

#endif