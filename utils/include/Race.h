#ifndef RACE_H
#define RACE_H

#include <string>
#include "Attributes.h"
#include "Species.h"

struct Race{
    Species species;
    std::string description;
    Attributes attributes;   // Basic attributes of race
    Attributes modifiers;    // Modifiers of attributes
};

#endif