#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Necromancer : public Jobs {
public:
    Necromancer();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif