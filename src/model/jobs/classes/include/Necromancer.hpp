#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Necromancer : public Jobs {
public:
    Necromancer();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif