#ifndef ROGUE_HPP
#define ROGUE_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Rogue : public Jobs {
public:
    Rogue();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif