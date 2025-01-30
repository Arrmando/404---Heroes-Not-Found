#include <string>
#include <vector>
#include <memory>
#include "./include/TechnicalSheet.hpp"

class AlliesSheetHolder {
private:
    const int maxAllies = 3;
    std::vector<TechnicalSheet> partyMembers;

public:
    // Construtor
    AlliesSheetHolder() {
        partyMembers.reserve(maxAllies);
    }

    // Método get que permite acessar os aliados
    std::vector<TechnicalSheet>& getAllies() {
        return partyMembers;
    }

    // Deletar ficha de aliado
    void deleteAllies(int indice) {
        if (indice >= 0 && indice < static_cast<int>(partyMembers.size())) {
            partyMembers.erase(partyMembers.begin() + indice);
        }
    }

    // Adicionar aliado
    void addAllies(const TechnicalSheet& newAllie) {
        if (static_cast<int>(partyMembers.size()) < maxAllies) { 
            partyMembers.push_back(newAllie);
        }
    }

    //bool hasAllies() const { //verifica se existe algum aliado
    //return !partyMenbers.empty();  

    size_t getNumAllies() const { //identifica quantos aliados foram contratados
        return partyMembers.size();
    }
}
