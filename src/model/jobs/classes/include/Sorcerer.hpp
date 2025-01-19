#ifndef SORCERER_h
#define SORCERER_h

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Sorcerer : public Jobs {
public:
    Sorcerer();

protected:
    void setJobSpecialTrait() override;
};

#endif