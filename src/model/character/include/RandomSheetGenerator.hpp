#ifndef RANDOM_SHEET_GENERATOR_HPP
#define RANDOM_SHEET_GENERATOR_HPP

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "TechnicalSheet.hpp"
#include "CharacterIncubator.hpp"
#include "Species.hpp"
#include "Classes.hpp"

class RandomSheetGenerator { //classe destinada pra gerar fichas aleátorias 
public:
    // Vetor para armazenar os personagens e seus nomes

    std::vector<std::pair<std::unique_ptr<RandomSheetGenerator>, std::string>> random;

    // Método para adicionar dados a uma ficha aleatória

    void addRandomSheetData(
        int level = 0,
        std::string characterName = "",
        Species specie = Species::HUMAN,
        Classes job = Classes:: WARRIOR
    );
};

#endif