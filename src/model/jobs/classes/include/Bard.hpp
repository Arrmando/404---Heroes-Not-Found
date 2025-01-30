#ifndef BARD_HPP
#define BARD_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Bard : public Jobs {
public:
    Bard();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif