#ifndef VIEWMODELBAR_HPP
#define VIEWMODELBAR_HPP
#include "../../telaCidade/include/viewCidade.hpp"
#include "../../../model/character/include/TechnicalSheet.hpp"

class ViewModelBar {
public:

    ViewModelBar(TechnicalSheet* character_) : character(character_) {}

    int getMoney() const;
    int getPrecoMecenario() const;
    int getQuantidadeMercenarios() const;
    bool podeComprarMercenario() const;
    void comprarMercenario(float amount);
    void mudarParaCidade();

private:
    TechnicalSheet* character;
};

#endif // VIEWMODEL_HPP
