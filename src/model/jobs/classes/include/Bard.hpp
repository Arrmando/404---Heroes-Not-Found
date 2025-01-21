#ifndef BARD_H
#define BARD_H

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Bard : public Jobs {
public:
    Bard();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif