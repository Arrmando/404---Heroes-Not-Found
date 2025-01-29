#ifndef DRUID_HPP
#define DRUID_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Druid : public Jobs {
public:
    Druid();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif