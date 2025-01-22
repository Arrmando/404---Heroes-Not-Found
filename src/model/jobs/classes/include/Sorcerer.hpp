#ifndef SORCERER_h
#define SORCERER_h

#include "Jobs.hpp"
#include "Attributes.hpp"
#include <iostream>
#include "AttributesProcessor.hpp"

class Sorcerer : public Jobs {
public:
    Sorcerer();

protected:
    void skill(AttributesProcessor& attributesProcessor, const int level) override;
};

#endif