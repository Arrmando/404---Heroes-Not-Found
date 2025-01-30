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
        int characterLevel, 
        std::string characterName, 
        Species characterSpecies, 
        Classes characterClasses
    );
    
};

#endif // !CHARACTER_INCUBATOR_HPP