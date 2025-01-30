#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Warrior : public Jobs {
public:
    Warrior();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif