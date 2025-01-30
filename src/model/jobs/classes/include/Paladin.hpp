#ifndef PALADIN_HPP
#define PALADIN_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Paladin : public Jobs {
public:
    Paladin();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif