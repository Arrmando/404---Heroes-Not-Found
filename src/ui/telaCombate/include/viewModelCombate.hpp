#ifndef VIEWMODEL_COMBATE_HPP
#define VIEWMODEL_COMBATE_HPP

#include <SFML/Graphics.hpp>

class ViewModelCombate {
public:
    ViewModelCombate();

    void handleAttack(); 
    void handleBossAttack();     
    void handleSpecial();    

    void handleAttackSpeed(); 
    
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

private:

    sf::Clock attackClock;

    float healthPlayer;
    float healthBoss;
    float damagePlayer;
    float damageBoss;
    float attackSpeed;
    float attackCooldown;
};

#endif
