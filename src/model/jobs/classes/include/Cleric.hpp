#ifndef CLERIC_HPP
#define CLERIC_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Cleric : public Jobs {
public:
    Cleric();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif