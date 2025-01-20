#include "./include/viewModelCidade.hpp"
#include "../telaBar/include/viewBar.hpp"
#include "../telaCombate/include/viewCombate.hpp"       
#include "../telaMenu/include/viewMenu.hpp"
// Gerenciador de janela única

void ViewModelCidade::fecharJanelaAtual() {
    if (janela && janela->isOpen()) {
        janela->close(); // Fecha a janela se estiver aberta
    }
}

void ViewModelCidade :: mudarParaBar(){
    Bar bar;
    bar.run();
}

void ViewModelCidade :: mudarParaMenu(){
    Menu menu;
    menu.run();
}

void ViewModelCidade :: mudarParaCombate(){
    CombatScreen combatScreen;
    combatScreen.run();
}
