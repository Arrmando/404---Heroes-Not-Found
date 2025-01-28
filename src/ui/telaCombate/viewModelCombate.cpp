#include "./include/viewModelCombate.hpp"
#include "./include/viewModelCombate.hpp"
#include "../telaCidade/include/viewCidade.hpp"
#include "../../model/character/include/TecnicalSheet.hpp"
#include <iostream>

ViewModelCombate::ViewModelCombate() {
    healthPlayer = 5000.0f;
    healthBoss = 1000.0f;   
    damagePlayer = 100.0f; 
    damageBoss = 1.0f;
    attackSpeed = 0.1f;
    attackCooldown = 0.1f;
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

void ViewModelCombate::setHealthAliado1(float newHealth) {
    healthBoss = newHealth;
}

void ViewModelCombate::setHealthAliado2(float newHealth) {
    healthBoss = newHealth;
}

void ViewModelCombate::setHealthAliado3(float newHealth) {
    healthBoss = newHealth;
}

void ViewModelCombate::handleAttack() {
    healthBoss -= damagePlayer;  
    if (healthBoss < 0) {
        healthBoss = 0;
    }

    std::cout << "Ataque! Dano causado: " << damagePlayer << std::endl;
    std::cout << "Vida do Boss: " << healthBoss << std::endl;

}

void ViewModelCombate::handleBossAttack() {
    healthPlayer -= damageBoss;  
    if (healthPlayer < 0) {
        healthPlayer = 0;

    }
    std::cout << "Ataque do Boss! Dano causado: " << damageBoss << std::endl;
    std::cout << "Vida do Jogador: " << healthPlayer << std::endl;
}

// velocidade de ataque do boss usando ataque por segundo
void ViewModelCombate::handleAttackSpeed() {
    float elapsedTime = attackClock.getElapsedTime().asSeconds();
    if (elapsedTime >= attackCooldown) {
        attackClock.restart();
        handleBossAttack();
}
    
}

void ViewModelCombate::handleSpecial() {
    std::cout << "Ação Especial Executada!" << std::endl;
}

void ViewModelCombate::handleEscapeButton() {
    Cidade cidade;
    cidade.run();
}