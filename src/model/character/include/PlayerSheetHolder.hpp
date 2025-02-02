#ifndef PLAYER_SHEET_HOLDER_HPP
#define PLAYER_SHEET_HOLDER_HPP

#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "TechnicalSheet.hpp"
#include "CharacterIncubator.hpp"
#include "Species.hpp"
#include "Classes.hpp"

class PlayerSheetHolder { //classe destinada pra ficha do jogador
public:
    // Vetor para armazenar os personagens e seus nomes

    std::vector<std::pair<std::unique_ptr<PlayerSheetHolder>, std::string>> player;

    // Método para adicionar um personagem

    void addPlayerData(
        int level = 0,
        std::string characterName = "",
        Species specie = Species::HUMAN,
        Classes job = Classes:: WARRIOR
    );
};

#endif