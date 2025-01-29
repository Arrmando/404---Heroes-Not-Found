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
    ) {
        return std::make_unique<TechnicalSheet>(characterName, characterLevel, characterSpecies, characterClasses);
    }
    
};
