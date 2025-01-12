// código para deixar o básico ou copiarmos para implementar raças novas

#ifndef race_H
#define race_H

#include "racesinterface.h"
#include <iostream>
#include <string>
#include <memory>

class RaceBase {
public:
    virtual void raceSpecialTrait() = 0;
    virtual void onStart() = 0;
    virtual void onDestroy() = 0;
    virtual ~RaceBase() = default;
};

//Raça Base

class Race : public RaceBase {
protected:
    float vida;
    float ataqueMagico;
    float ataqueFisico;
    float defesaMagica;
    float defesaFisica;
    std::string nome;

public:
    Race(float baseVida, float baseAtaqueMagico, float baseAtaqueFisico,
         float baseDefesaMagica, float baseDefesaFisica, 
         float escalaVida, float escalaAtaqueMagico, float escalaAtaqueFisico,
         float escalaDefesaMagica, float escalaDefesaFisica, 
         const std::string& nomeRaça)
        : vida(baseVida * escalaVida / 100.0f),
          ataqueMagico(baseAtaqueMagico * escalaAtaqueMagico / 100.0f),
          ataqueFisico(baseAtaqueFisico * escalaAtaqueFisico / 100.0f),
          defesaMagica(baseDefesaMagica * escalaDefesaMagica / 100.0f),
          defesaFisica(baseDefesaFisica * escalaDefesaFisica / 100.0f),
          nome(nomeRaça) {}

    virtual void raceSpecialTrait() override {
        std::cout << nome << " não possui habilidades especiais definidas.\n";
    }

    virtual void onStart() override {
        std::cout << nome << " entrou no jogo!\n";
    }

    virtual void onDestroy() override {
        std::cout << nome << " foi derrotado.\n";
    }

        // Aqui você pode setar atributos específicos se necessário
    

   

    // Getters para os atributos (opcional, para futuras funcionalidades ou se formos fazer de outra maneira)

    void printAttributes() const {
        std::cout << "Raça: " << nome << "\n";
        std::cout << "Vida: " << vida << "\n";
        std::cout << "Ataque Mágico: " << ataqueMagico << "\n";
        std::cout << "Ataque Físico: " << ataqueFisico << "\n";
        std::cout << "Defesa Mágica: " << defesaMagica << "\n";
        std::cout << "Defesa Física: " << defesaFisica << "\n";
    }

};
#endif //race_H

git config --global user.name "EliasDMS"
git config --global user.email "eliasdaniel_ms@outlook.com.br"