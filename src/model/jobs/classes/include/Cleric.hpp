#ifndef CLERIC_H
#define CLERIC_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Cleric : public Jobs {
public:
    Cleric();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif