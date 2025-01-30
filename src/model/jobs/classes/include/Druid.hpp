#ifndef DRUID_HPP
#define DRUID_HPP

#include <iostream>
#include "Jobs.hpp"
#include "Attributes.hpp"
#include "AttributesProcessor.hpp"

class Druid : public Jobs {
public:
    Druid();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif