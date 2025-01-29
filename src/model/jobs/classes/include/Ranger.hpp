#ifndef RANGER_H
#define RANGER_H

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Ranger : public Jobs {
public:
    Ranger();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif