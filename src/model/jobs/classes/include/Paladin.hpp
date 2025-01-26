#ifndef PALADIN_H
#define PALADIN_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Paladin : public Jobs {
public:
    Paladin();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif