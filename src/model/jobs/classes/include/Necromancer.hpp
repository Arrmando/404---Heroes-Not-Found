#ifndef NECROMANCER_H
#define NECROMANCER_H

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