#ifndef NAME_GENERATOR_HPP
#define NAME_GENERATOR_HPP

#include <string>
#include <vector>
#include <random>
#include "Species.hpp"

class NameGenerator {
public:
    NameGenerator();
    std::string randomName(Species type);

private:
    std::vector<std::pair<Species, std::vector<std::string>>> speciesNames;
    std::random_device rd;
    std::mt19937 gen;
};

#endif // NAMEGENERATOR_HPP