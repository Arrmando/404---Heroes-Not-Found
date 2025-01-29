#ifndef WARRIOR_HPP
#define WARRIOR_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Warrior : public Jobs {
public:
    Warrior();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif