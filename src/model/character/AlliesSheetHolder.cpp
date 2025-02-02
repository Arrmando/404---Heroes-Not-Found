#include <string>
#include <vector>
#include <memory>
#include "./include/TechnicalSheet.hpp"
#include "AlliesSheetHolder.hpp"

class AlliesSheetHolder {
private:
   const size_t maxAllies = 3;
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
   void deleteAllies(size_t indice) {
        if (indice < partyMembers.size()) {
            partyMembers.erase(partyMembers.begin() + indice);
        } else {
            throw std::out_of_range("Invalid index for deleting ally.");
        }
    }

    // Adicionar aliado
    void addAllies(const TechnicalSheet& newAllie) {
        if (partyMembers.size() < maxAllies) {
            partyMembers.push_back(newAllie);
        } else {
            throw std::runtime_error("Cannot add more allies; party is full.");
        }
    }
  
    //verifica quantidade de aliados
     size_t getNumAllies() const {
        return partyMembers.size();
    }
}
