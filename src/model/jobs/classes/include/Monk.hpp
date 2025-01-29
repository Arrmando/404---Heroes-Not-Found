#ifndef MONK_H
#define MONK_H

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Monk : public Jobs {
public:
    Monk();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif