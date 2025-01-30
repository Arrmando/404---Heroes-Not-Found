#ifndef CHARACTER_PROCESSOR_HPP
#define CHARACTER_PROCESSOR_HPP

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "TechnicalSheet.hpp"
#include "CharacterIncubator.hpp"
#include "Species.hpp"
#include "Classes.hpp"

class CharacterProcessor { //classe destinada a gerenciar os personagens
public:
    // Vetor para armazenar os personagens e seus nomes
    std::vector<std::pair<std::unique_ptr<TechnicalSheet>, std::string>> characters;

    // Método para adicionar um personagem
    void addCharacter(
        int level = 0,
        std::string characterName = "",
        Species specie = Species::HUMAN,
        Classes job = Classes:: WARRIOR
    );
};

#endif