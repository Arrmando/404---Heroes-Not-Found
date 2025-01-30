#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Barbarian : public Jobs {
public:
    Barbarian();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif