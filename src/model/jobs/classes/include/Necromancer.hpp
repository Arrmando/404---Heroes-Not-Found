#ifndef NECROMANCER_H
#define NECROMANCER_H

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