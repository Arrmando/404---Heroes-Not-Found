#ifndef CHARACTER_INCUBATOR_HPP
#define CHARACTER_INCUBATOR_HPP

#include <memory>
#include <string>
#include "TechnicalSheet.hpp"
#include "Species.hpp"
#include "Classes.hpp"

class CharacterIncubator {
public:

    static std::unique_ptr<TechnicalSheet> createCharacter(
        std::string characterName, 
        int characterLevel, 
        Species characterSpecies, 
        Classes characterClasses
    );
    
};

#endif // !CHARACTER_INCUBATOR_HPP