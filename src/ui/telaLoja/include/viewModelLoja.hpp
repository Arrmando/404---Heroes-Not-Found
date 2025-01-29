#ifndef VIEWMODELLOJA_HPP
#define VIEWMODELLOJA_HPP

class ViewModelLoja {
public:
    
    int getMoney() const;
    int getPrecoArma() const;
    int getPrecoArmadura() const;
    int getQuantidadeArmas() const;
    int getQuantidadeArmaduras() const;
    bool podeComprarArma() const;
    bool podeComprarArmadura() const;
    void comprarArma();
    void comprarArmadura();
    void mudarParaCidade();

private:

};

#endif // VIEWMODEL_HPP
