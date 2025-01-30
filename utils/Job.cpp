#include <string>
#include "../../utils/include/Attributes.hpp"
#include "../../utils/include/Classes.hpp"

struct Job{
    Classes occupation;
    std::string description;
    Attributes modifiers;    // Modifiers of attributes
};