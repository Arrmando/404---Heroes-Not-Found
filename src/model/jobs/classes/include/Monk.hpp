#ifndef MONK_HPP
#define MONK_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Monk : public Jobs {
public:
    Monk();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif