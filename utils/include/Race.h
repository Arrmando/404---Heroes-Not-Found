#ifndef RACE_H
#define RACE_H

#include <string>

enum class Species {
    HUMAN,
    ELF,
    DEMIHUMAN,
    FAIRY,
    GIANT,
    ORC,
    DRACONIC,
    UNDEAD
};

struct Attributes {
    float hp; 
    float magicAttack;
    float physicalAttack;
    float magicDefense;
    float physicalDefense;
};

struct Race{
    Species species;
    std::string description;
    Attributes attributes;   // Basic attributes of race
    Attributes modifiers;    // Modifiers of attributes
};

#endif