#ifndef MAGE_HPP
#define MAGE_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Mage : public Jobs {
public:
    Mage();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif