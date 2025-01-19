#ifndef DRUID_H
#define DRUID_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>

class Druid : public Jobs {
public:
    Druid();

protected:
    void setJobSpecialTrait() override;
};

#endif