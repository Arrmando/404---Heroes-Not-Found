#include <memory>
#include <string>
#include "../../model/character/include/TechnicalSheet.hpp"
#include "../../../utils/include/Species.hpp"
#include "../../../utils/include/Classes.hpp"
#include "CharacterIncubator.hpp"

/**
 * Creates a new character with the provided attributes.
 *
 * @param characterLevel The level of the character.
 * @param characterName The name of the character.
 * @param characterSpecies The species of the character.
 * @param characterClasses The classes the character belongs to.
 * @return A unique pointer to a TechnicalSheet instance representing the created character.
 */
std::unique_ptr<TechnicalSheet> CharacterIncubator::createCharacter(
    int characterLevel, 
    std::string characterName, 
    Species characterSpecies, 
    Classes characterClasses
) {
    return std::make_unique<TechnicalSheet>(characterLevel, characterName, characterSpecies, characterClasses);
}
