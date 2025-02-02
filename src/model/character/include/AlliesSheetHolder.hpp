
#ifndef ALLIES_SHEET_HOLDER_HPP
#define ALLIES_SHEET_HOLDER_HPP

#include <string>
#include <vector>
#include <memory>
#include <stdexcept>
#include "./include/TechnicalSheet.hpp"

class AlliesSheetHolder {
private:
    const size_t maxAllies = 3;
    std::vector<TechnicalSheet> partyMembers;

public:
    // Construtor
    AlliesSheetHolder();

    // Método get que permite acessar os aliados
    std::vector<TechnicalSheet>& getAllies();

    // Deletar ficha de aliado
    void deleteAllies(size_t indice);

    // Adicionar aliado
    void addAllies(const TechnicalSheet& newAllie);

    // Verifica quantidade de aliados
    size_t getNumAllies() const;
};

#endif // ALLIES_SHEET_HOLDER_HPP