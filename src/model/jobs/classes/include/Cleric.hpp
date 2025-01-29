#ifndef CLERIC_H
#define CLERIC_H

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