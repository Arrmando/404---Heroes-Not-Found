#ifndef PALADIN_H
#define PALADIN_H

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Paladin : public Jobs {
public:
    Paladin();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif