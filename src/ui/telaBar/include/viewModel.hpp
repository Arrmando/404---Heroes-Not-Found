#ifndef VIEWMODEL_HPP
#define VIEWMODEL_HPP

class ViewModel {
public:
    
    int getMoney() const;
    int getPrecoMecenario() const;
    int getQuantidadeMercenarios() const;
    bool podeComprarMercenario() const;
    void comprarMercenario();

private:

};

#endif // VIEWMODEL_HPP
