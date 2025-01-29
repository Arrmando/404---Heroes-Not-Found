#ifndef MAGE_HPP
#define MAGE_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Mage : public Jobs {
public:
    Mage();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif