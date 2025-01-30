#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Necromancer : public Jobs {
public:
    Necromancer();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif