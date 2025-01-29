#ifndef PALADIN_HPP
#define PALADIN_HPP

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