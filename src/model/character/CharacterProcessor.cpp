#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "../../model/character/include/TechnicalSheet.hpp"
#include "../../model/character/include/CharacterIncubator.hpp"
#include "../../../utils/include/Species.hpp"
#include "../../../utils/include/Classes.hpp"
#include "CharacterProcessor.hpp"

/**
 * Adds a new character to the characters vector.
 * The character is created using the CharacterIncubator class.
 *
 * @param level The level of the character (default: 0).
 * @param characterName The name of the character (default: "").
 * @param specie The species of the character (default: Species::HUMAN).
 * @param job The class/job of the character (default: Classes::WARRIOR).
 */
void CharacterProcessor::addCharacter(
    int level,
    std::string characterName,
    Species specie,
    Classes job
) {
    try {
        // Create a new character using the CharacterIncubator
        std::unique_ptr<TechnicalSheet> character = CharacterIncubator::createCharacter(
            level,
            characterName,
            specie,
            job
        );

        // Add the character and its name to the vector
        characters.emplace_back(std::move(character), characterName);
    } catch (const std::exception& e) {
        // Handle any exceptions that occur during character creation
        std::cerr << "Error adding character: " << e.what() << '\n';
    }
}