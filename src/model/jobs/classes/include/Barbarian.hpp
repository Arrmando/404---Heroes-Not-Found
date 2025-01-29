#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Barbarian : public Jobs {
public:
    Barbarian();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif