#include <string>
#include <memory>
#include "TechnicalSheet.hpp"
#include <iostream>
#include <random>
#include "RandomName.hpp"

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
    //inicialização de variáveis lógicas
    std::mt19937 gen;
    int min;
    int max;
    int selectedRandomNumber;

    //inicialização de variaveis para a ficha
    int level = 1;
    std::string name = "Morpheus";
    Species species_ = Human;
    Classes classes_ = Mage;
    TechnicalSheet RandomSheet;

    int getRandomNumber(int min, int max) {
        std::uniform_int_distribution<int> dist(min, max);
        return dist(gen);
    }

//define raça, classe e aumento de dificuldade
    void definePlace(places c) {
    switch (c) {
        case castleDoors:
            min = 0;
            max = 9;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleDoors) + 1) == 0) {
                    break;
                }
            }
            species_ = static_cast<Species>(selectedRandomNumber);

            min = 0;
            max = 11;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleDoors) + 1) == 0) {
                    break;
                }
            }
            classes_ = static_cast<Classes>(selectedRandomNumber);
            break;

        case castleRooms:
            min = 0;
            max = 9;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleRooms) + 1) == 0) {
                    break;
                }
            }
            species_ = static_cast<Species>(selectedRandomNumber);

            min = 0;
            max = 11;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleRooms) + 1) == 0) {
                    break;
                }
            }
            classes_ = static_cast<Classes>(selectedRandomNumber);

            level += 50;
            break;

        case castleKing:
            min = 0;
            max = 9;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleKing) + 1) == 0) {
                    break;
                }
            }
            species_ = static_cast<Species>(selectedRandomNumber);

            min = 0;
            max = 11;
            while (true) {
                selectedRandomNumber = getRandomNumber(min, max);
                if (selectedRandomNumber % (static_cast<int>(castleKing) + 1) == 0) {
                    break;
                }
            }
            classes_ = static_cast<Classes>(selectedRandomNumber);

            level += 100;
            break;
    }
}

//define xp
    void defineLevel(dificultType D) {
        switch(D) {
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
    //gerar fichas aleatórias
 RandomSheetGenerator(places local, dificultType dificuldade) 
    : gen(std::random_device{}()) { 
    defineLevel(dificuldade);
    definePlace(local);
    name = getRandomName(species_);
    RandomSheet = TechnicalSheet(level, name, species_, classes_);
}