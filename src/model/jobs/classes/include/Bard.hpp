#ifndef BARD_H
#define BARD_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Bard : public Jobs {
public:
    Bard();

protected:
    void setJobSpecialTrait() override;
};

#endif