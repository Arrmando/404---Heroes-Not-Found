#include "viewModelCombate.hpp"
#include "../telaCidade/include/viewCidade.hpp"

ViewModelCombate::ViewModelCombate() {
    healthPlayer = 5000.0f;
    healthBoss = 50000.0f;   
    healthAliado1 = 150.0f;
    healthAliado2 = 100.0f;
    healthAliado3 = 50.0f;

    damagePlayer = 100.0f; 
    damageBoss = 30.0f;
    attackSpeed = 0.1f;
    attackCooldown = 0.1f;

    // Configurar DPS dos aliados
    dpsAliado1 = 50.0f;
    dpsAliado2 = 25.0f;
    dpsAliado3 = 10.0f;

    // Configurar danos especiais
    specialDamageAliado1 = 500.0f;
    specialDamageAliado2 = 250.0f;
    specialDamageAliado3 = 100.0f;
}

float ViewModelCombate::getHealthBoss() {
    return healthBoss;
}

float ViewModelCombate::getHealthPlayer() {
    return healthPlayer;
}

float ViewModelCombate::getHealthAliado1() {
    return healthAliado1;
}

float ViewModelCombate::getHealthAliado2() {
    return healthAliado2;
}

float ViewModelCombate::getHealthAliado3() {
    return healthAliado3;
}

void ViewModelCombate::setHealthBoss(float newHealth) {
    healthBoss = newHealth;
}

void ViewModelCombate::setHealthPlayer(float newHealth) {
    healthPlayer = newHealth;
}

void ViewModelCombate::setHealthAliado1(float newHealth) {
    healthAliado1 = newHealth;
}

void ViewModelCombate::setHealthAliado2(float newHealth) {
    healthAliado2 = newHealth;
}

void ViewModelCombate::setHealthAliado3(float newHealth) {
    healthAliado3 = newHealth;
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

void ViewModelCombate::handleSpecial1() {
    if (healthAliado1 > 0) {
        healthBoss -= specialDamageAliado1;
        healthBoss = std::max(healthBoss, 0.0f);
    }
}

void ViewModelCombate::handleSpecial2() {
    if (healthAliado2 > 0) {
        healthBoss -= specialDamageAliado2;
        healthBoss = std::max(healthBoss, 0.0f);
    }
}

void ViewModelCombate::handleSpecial3() {
    if (healthAliado3 > 0) {
        healthBoss -= specialDamageAliado3;
        healthBoss = std::max(healthBoss, 0.0f);
    }
}

void ViewModelCombate::handleAttackSpeed() {
    // Ataque do boss
    float elapsedTime = attackClock.getElapsedTime().asSeconds();
    if (elapsedTime >= attackCooldown) {
        attackClock.restart();
        handleBossAttack();
    }

    // DPS dos aliados
    float dpsTime = aliadosDPSClock.getElapsedTime().asSeconds();
    if (dpsTime >= 1.0f) {
        aliadosDPSClock.restart();
        if (healthAliado1 > 0) healthBoss -= dpsAliado1;
        if (healthAliado2 > 0) healthBoss -= dpsAliado2;
        if (healthAliado3 > 0) healthBoss -= dpsAliado3;
        healthBoss = std::max(healthBoss, 0.0f);
    }
}

void ViewModelCombate::applyClickDamage(float damage) {
    healthBoss -= damage;
    healthBoss = std::max(healthBoss, 0.0f);
}

void ViewModelCombate::handleEscapeButton() {
    Cidade cidade;
    cidade.run();
}
