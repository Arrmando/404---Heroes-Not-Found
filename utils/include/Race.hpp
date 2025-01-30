#ifndef RACE_HPP
#define RACE_HPP

#include <string>
#include "./Attributes.hpp"
#include "./Species.hpp"

struct Race{
    Species species;
    std::string description;
    Attributes attributes;   // Basic attributes of race
    Attributes modifiers;    // Modifiers of attributes
};

#endif