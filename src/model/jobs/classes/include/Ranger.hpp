#ifndef RANGER_HPP
#define RANGER_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Ranger : public Jobs {
public:
    Ranger();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif