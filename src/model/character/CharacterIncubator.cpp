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
    ) {
        return std::make_unique<TechnicalSheet>(characterName, characterLevel, characterSpecies, characterClasses);
    }
    
};
