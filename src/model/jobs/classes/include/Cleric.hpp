#ifndef CLERIC_HPP
#define CLERIC_HPP

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