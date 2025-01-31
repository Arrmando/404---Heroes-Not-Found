#include "./include/viewModelCombate.hpp"
#include "./include/viewModelCombate.hpp"
#include "../telaCidade/include/viewCidade.hpp"
#include "../../model/character/include/TechnicalSheet.hpp"
#include "../../model/character/include/PlayerSheetHolder.hpp"
#include "../../model/character/include/RandomSheetGenerator.hpp"
#include "../../model/character/include/AlliesSheetHolder.hpp"
#include <iostream>
#include <vector>


//função para pegar imagem de acordo com raça GUILHERME



ViewModelCombate::ViewModelCombate() { //inicializar 

    TechnicalSheet jogador = playerHolder.getPlayerConst(); // copia ficha do jogador
    
    AlliesSheetHolder holder;
    int indice = holder.getNumAllies();
    if (indice != 0) {
    std::vector<TechnicalSheet> allies = holder.getAllies(); //copia ficha dos alidos

    TechnicalSheet enemy;
    }
}

ViewModelCombate::generateEnemy(){

    enemy = RandomSheetGenerator(0 ,0);

}

float ViewModelCombate::getHealthPlayer() { // status atual de vida    //fazer uma igual para status total de vida

     allies[0].atacar();
    return jogador.hp;// alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando


    // Chamando um método diretamente do primeiro aliado
    allies[0].physicalAttack();  // Chama o método physicalAttack() de ally1  


}



float ViewModelCombate::getHealthBoss() {   //fazer uma igual para status total de vida
    return healthBoss;// alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando
}

void ViewModelCombate::getCurrentHealthBoss() { // status atual de vida 
    healthBoss = newHealth;// alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando
}



void ViewModelCombate::HealthAliado(int index) { // status atual de vida    //fazer uma igual para status total de vida

     allies[0].atacar();
    healthBoss = newHealth;// alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando
}


void ViewModelCombate::handleAttack() {  //outra para player
    //int damage = getplayerphiscalatack()
    //boss.hp = receivePhysicalDamage(damage)
    healthBoss -= damagePlayer;  // alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando
    if (healthBoss < 0) {
        healthBoss = 0;
    }

    std::cout << "Ataque! Dano causado: " << damagePlayer << std::endl;
    std::cout << "Vida do Boss: " << healthBoss << std::endl;
}

void ViewModelCombate::handleBossAttack() {
    healthPlayer -= damageBoss;  // alterar por lógica utilizando metodos do TechnicalSheet.hpp   Elias e Armando
    if (healthPlayer < 0) {
        healthPlayer = 0;
    }
    std::cout << "Ataque do Boss! Dano causado: " << damageBoss << std::endl;
    std::cout << "Vida do Jogador: " << healthPlayer << std::endl;
}

// velocidade de ataque do boss usando ataque por segundo
void ViewModelCombate::handleAttackSpeedBoss() {
    float elapsedTime = attackClock.getElapsedTime().asSeconds();
    if (elapsedTime >= attackCooldown) {
        attackClock.restart();
        handleBossAttack();
    }
}



void ViewModelCombate::handleAttackSpeedAllies() {
    float elapsedTime = attackClock.getElapsedTime().asSeconds();
    if (elapsedTime >= attackCooldown) {
        attackClock.restart();
        ();
    }
}

void ViewModelCombate::handleSpecial() { // um para player// um para aliados (recebe indice)
    std::cout << "Ação Especial Executada!" << std::endl;
}

void ViewModelCombate::handleEscapeButton() {
    Cidade cidade;
    cidade.run();
}
// boss ataca quem tiver maior defesa

// criar função que devolve indice

// definir função quem usa especial em quem +++DIFICIL
// função que devolve o nome aliado/jogador/boss
// função get imagem


if (hp <= 0){
    chamar funçao morrer.
}