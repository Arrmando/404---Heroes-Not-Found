#ifndef RACE_H
#define RACE_H

#include <string>
#include "../utils/include/Attributes.hpp"
#include "../utils/include/Species.hpp"

struct Race{
    Species species;
    std::string description;
    Attributes attributes;   // Basic attributes of race
    Attributes modifiers;    // Modifiers of attributes
};

#endif