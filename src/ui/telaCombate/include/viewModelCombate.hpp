#ifndef VIEWMODEL_COMBATE_HPP
#define VIEWMODEL_COMBATE_HPP

class ViewModelCombate {
public:
    ViewModelCombate();
    
    void handleAttack();      
    void handleSpecial();     
    
    float getHealthBoss();    
    void setHealthBoss(float newHealth);  

    float getHealthPlayer();    
    void setHealthPlayer(float newHealth);  

private:
    float healthPlayer;
    float healthBoss;
    float damagePlayer;
};

#endif
