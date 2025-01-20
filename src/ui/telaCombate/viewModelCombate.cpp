// viewModelCombate.cpp

#include "viewModelCombate.hpp"
#include <iostream>

ViewModelCombate::ViewModelCombate() {
    healthPlayer = 5000.0f;
    healthBoss = 1000.0f;   
    damagePlayer = 100.0f; 
}

float ViewModelCombate::getHealthPlayer() {
    return healthPlayer;
}

float ViewModelCombate::getHealthBoss() {
    return healthBoss;
}

void ViewModelCombate::setHealthBoss(float newHealth) {
    healthBoss = newHealth;
}

void ViewModelCombate::setHealthPlayer(float newHealth) {
    healthPlayer = newHealth;
}

void ViewModelCombate::handleAttack() {
    healthBoss -= damagePlayer;  // Diminuir a vida do boss com o dano do player
    if (healthBoss < 0) {
        healthBoss = 0;
    }

    std::cout << "Ataque! Dano causado: " << damagePlayer << std::endl;
    std::cout << "Vida do Boss: " << healthBoss << std::endl;

    
}

void ViewModelCombate::handleSpecial() {
    std::cout << "Ação Especial Executada!" << std::endl;
}
