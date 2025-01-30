#ifndef ALLIES_SHEET_HOLDER_HPP
#define ALLIES_SHEET_HOLDER_HPP

#include <vector>
#include "TechnicalSheet.hpp"

class AlliesSheetHolder {
private:
    const int maxAllies = 3;
    std::vector<TechnicalSheet> partyMembers;

public:
    // Construtor
    AlliesSheetHolder();

    // Método get que permite acessar os aliados
    std::vector<TechnicalSheet>& getAllies();

    // Deletar ficha de aliado
    void deleteAllies(int indice);

    // Adicionar aliado
    void addAllies(const TechnicalSheet& newAllie);

    // Retorna o número de aliados
    size_t getNumAllies() const;
};

#endif // ALLIES_SHEET_HOLDER_HPP