#ifndef MONK_HPP
#define MONK_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Monk : public Jobs {
public:
    Monk();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif