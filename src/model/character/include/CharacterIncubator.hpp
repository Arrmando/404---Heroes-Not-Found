#ifndef CHARACTER_INCUBATOR_HPP
#define CHARACTER_INCUBATOR_HPP

#include <memory>
#include <string>
#include "../model/character/include/TechnicalSheet.hpp"
#include "../utils/include/Species.hpp"
#include "../utils/include/Classes.hpp"

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