#ifndef DRUID_HPP
#define DRUID_HPP

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Druid : public Jobs {
public:
    Druid();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif