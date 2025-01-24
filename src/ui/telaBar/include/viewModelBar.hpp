#ifndef VIEWMODELBAR_HPP
#define VIEWMODELBAR_HPP

class ViewModelBar {
public:
    
    int getMoney() const;
    int getPrecoMecenario() const;
    int getQuantidadeMercenarios() const;
    bool podeComprarMercenario() const;
    void comprarMercenario();
    void mudarParaCidade();

private:

};

#endif // VIEWMODEL_HPP
