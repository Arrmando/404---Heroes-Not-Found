#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Barbarian : public Jobs {
public:
    Barbarian();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif