#ifndef RANGER_HPP
#define RANGER_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Ranger : public Jobs {
public:
    Ranger();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif