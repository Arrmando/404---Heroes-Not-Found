#ifndef BARD_H
#define BARD_H

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Bard : public Jobs {
public:
    Bard();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif