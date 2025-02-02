#include <string>
#include <memory>
#include "TechnicalSheet.hpp"
#include <iostream>
#include <random>
#include "RandomName.hpp"
#include "RandomSheetGenerator.hpp"

enum dificultType {
    
    VeryEasy,
    Easy,
    EarlyMedium,
    Medium,
    AlmostHard,
    EarlyHard,
    Hard,
    TruHard,
    Hardcore,
    Hell
};

enum places {
    castleDoors,
    castleRooms,
    castleKing
};

class RandomSheetGenerator { 
private:

    // Inicialização de variáveis lógicas

    std::mt19937 gen;
    int min;
    int max;
    int selectedRandomNumber;

    // Inicialização de variáveis para a ficha

    int level = 1;
    std::string name = "Morpheus";
    Species species_ = Human;
    Classes classes_ = Mage;
    TechnicalSheet RandomSheet;

    // Função para gerar números aleatórios

    int getRandomNumber(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

    // Função para definir espécie e classe com base no local

    void defineSpeciesAndClass(places place) {
        min = 0;
        max = 9;
        while (true) {
            selectedRandomNumber = getRandomNumber(min, max);
            if (selectedRandomNumber % (static_cast<int>(place) + 1) == 0) {
                break;
            }
        }
        species_ = static_cast<Species>(selectedRandomNumber);

        min = 0;
        max = 11;
        while (true) {
            selectedRandomNumber = getRandomNumber(min, max);
            if (selectedRandomNumber % (static_cast<int>(place) + 1) == 0) {
                break;
            }
        }
        classes_ = static_cast<Classes>(selectedRandomNumber);
    }

    // Define o local e ajusta o nível

    void definePlace(places place) {
        defineSpeciesAndClass(place);

        switch (place) {
            case castleDoors:
                break;
            case castleRooms:
                level += 50;
                break;
            case castleKing:
                level += 100;
                break;
        }
    }

    // Define o nível com base na dificuldade

    void defineLevel(dificultType difficulty) {
        switch(difficulty) {
            case VeryEasy:   min = 0;   max = 10; break;
            case Easy:       min = 10;  max = 20; break;
            case EarlyMedium:min = 20;  max = 30; break;
            case Medium:     min = 30;  max = 40; break;
            case AlmostHard: min = 40;  max = 50; break;
            case EarlyHard:  min = 50;  max = 60; break;
            case Hard:       min = 60;  max = 70; break;
            case TruHard:    min = 70;  max = 80; break;
            case Hardcore:   min = 80;  max = 90; break;
            case Hell:       min = 90;  max = 100; break;
        }
        level = getRandomNumber(min, max);
    }

public:
    // Construtor para gerar fichas aleatórias

    RandomSheetGenerator(places place, dificultType difficulty) 
        : gen(std::random_device{}()) { 
        defineLevel(difficulty);
        definePlace(place);
        name = getRandomName(species_);
        RandomSheet = TechnicalSheet(level, name, species_, classes_);
    }

    // Método para obter a ficha gerada

    const TechnicalSheet& getRandomSheet() const {
        return RandomSheet;
    }
};