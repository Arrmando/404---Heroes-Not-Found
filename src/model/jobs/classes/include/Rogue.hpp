#ifndef ROGUE_h
#define ROGUE_h

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Rogue : public Jobs {
public:
    Rogue();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif