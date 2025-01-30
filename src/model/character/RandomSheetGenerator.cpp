#include <string>
#include <memory>
#include "TechnicalSheet.hpp"
#include <iostream>
#include <random>



//                                    Species 0 ~ 9
//                                    Classes 0 ~ 11
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
}



class RandomSheetGenerator{ 
private:

    int min;
    int max;
    // Atributos privados da classe
    int level = 1;
    std::string name = "Morpheus";
    Species species_ = Human;
    Classes classes_ = Mage;
    TechnicalSheet player;


    int defineLevel(dificultType D){
    switch(D){

    case VeryEasy
        min = 0;
        max = 10;
        break;

    case Easy,
        min = 0;
        max = 10;
        break;
        
    case EarlyMedium,
        min = 0;
        max = 10;
        break;

    case Medium
        min = 0;
        max = 10;
        break;

    case AlmostHard
        min = 0;
        max = 10;
        break;

    case EarlyHard
        min = 0;
        max = 10;
        break;

    case Hard
        min = 0;
        max = 10;
        break;

    case TruHard
        min = 0;
        max = 10;
        break;

    case Hardcore
        min = 0;
        max = 10;
        break;

    case Hell
        min = 0;
        max = 10;
        break;

    }

}



    int getRandomNumber(int min, int max) {
    std::random_device rd;   // Dispositivo de aleatoriedade (se disponível)
    std::mt19937 gen(rd());  // Gerador Mersenne Twister
    std::uniform_int_distribution<int> dist(min, max); // Distribuição uniforme

    return dist(gen);
}


public:
    // Construtor que inicializa o player com os valores de level, name, species e classes
    PlayerSheetHolder() 
        : player(level, name, species_, classes_) {}
}