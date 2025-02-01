#ifndef VIEWMODEL_COMBATE_HPP
#define VIEWMODEL_COMBATE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class ViewModelCombate {
public:
    ViewModelCombate();

    void handleAttack(); 
    void handleBossAttack();     
    void handleSpecial1(); // Alterado para específicos
    void handleSpecial2();
    void handleSpecial3(); 

    void handleAttackSpeed(); 
    void handleEscapeButton();
    
    // Getters e Setters
    float getHealthBoss();    
    void setHealthBoss(float newHealth);  
    float getHealthPlayer();    
    void setHealthPlayer(float newHealth);  
    float getHealthAliado1();
    void setHealthAliado1(float newHealth);
    float getHealthAliado2();
    void setHealthAliado2(float newHealth);
    float getHealthAliado3();
    void setHealthAliado3(float newHealth);

    void applyClickDamage(float damage); // Novo método para dano por clique

private:
    sf::Clock attackClock;
    sf::Clock aliadosDPSClock; // Relógio para DPS dos aliados

    float healthPlayer;
    float healthBoss;
    float healthAliado1;
    float healthAliado2;
    float healthAliado3;

    float damagePlayer;
    float damageBoss;
    float attackSpeed;
    float attackCooldown;

    // Dano por segundo dos aliados
    float dpsAliado1;
    float dpsAliado2;
    float dpsAliado3;

    // Dano especial dos aliados
    float specialDamageAliado1;
    float specialDamageAliado2;
    float specialDamageAliado3;
};

#endif