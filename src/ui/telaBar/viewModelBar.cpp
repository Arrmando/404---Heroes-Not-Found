#include "./include/viewModelBar.hpp"

ViewModelBar::ViewModelBar(TechnicalSheet* character_)
    : character(character_) {}

int ViewModelBar::getMoney() const {
    return character->dracmas; // Retorna o dinheiro do personagem
}

void ViewModelBar::comprarMercenario(float amount) {
    if (character->dracmas >= amount) {
        character->dracmas -= amount; // Deduz o dinheiro
    }
}

void ViewModelBar::mudarParaCidade() {
    Cidade cidade;
    cidade.run();
}
