#include <memory>
#include <string>
#include "JobIncubator.hpp"

/**
 * Creates a new job object based on the provided job type.
 * This method uses a factory pattern to instantiate the appropriate job class.
 *
 * @param type The type of job to create (from the Classes enum).
 * @return A unique_ptr to the created job object.
 * @throws std::invalid_argument If an invalid job type is provided.
 */
std::unique_ptr<JobInterface> JobIncubator::createJob(Classes type) {
    switch (type) {
        case Classes::BARBARIAN:
            return std::make_unique<Barbarian>();
        case Classes::BARD:
            return std::make_unique<Bard>();
        case Classes::DRUID:
            return std::make_unique<Druid>();
        case Classes::MAGE:
            return std::make_unique<Monk>();
        case Classes::NECROMANCER:
            return std::make_unique<Necromancer>();
        case Classes::PALADIN:
            return std::make_unique<Paladin>();
        case Classes::RANGER:
            return std::make_unique<Ranger>();
        case Classes::ROGUE:
            return std::make_unique<Rogue>();
        case Classes::SORCERER:
            return std::make_unique<Sorcerer>();
        case Classes::WARRIOR:
            return std::make_unique<Warrior>();
        default:
            throw std::invalid_argument("Invalid classes type provided.");
    }
}