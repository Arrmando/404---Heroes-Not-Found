#ifndef CLERIC_HPP
#define CLERIC_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Cleric : public Jobs {
public:
    Cleric();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif