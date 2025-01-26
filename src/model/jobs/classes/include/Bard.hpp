#ifndef BARD_HPP
#define BARD_HPP

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