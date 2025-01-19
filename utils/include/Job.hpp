#ifndef JOB_H
#define JOB_H

#include <string>
#include "Attributes.hpp"
#include "Classes.hpp"

struct Job{
    Classes occupation;
    std::string description;
    Attributes attributes;   // Job basic attributes
    Attributes modifiers;    // Modifiers of attributes
};

#endif