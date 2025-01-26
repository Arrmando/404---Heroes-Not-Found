#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Warrior : public Jobs {
public:
    Warrior();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif