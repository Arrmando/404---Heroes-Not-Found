#ifndef SORCERER_HPP
#define SORCERER_HPP

#include "../model/jobs/include/Jobs.hpp"
#include "../utils/include/Attributes.hpp"
#include <iostream>
#include "../model/attributes/include/AttributesProcessor.hpp"

class Sorcerer : public Jobs {
public:
    Sorcerer();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif