#include <string>
#include <memory>
#include "./include/TechnicalSheet.hpp"


class PlayerSheetHolder { 
    // Atributos privados da classe
    int level = 1;
    std::string name = "Morpheus";
    Species species_ = Human;
    Classes classes_ = Mage;
    TechnicalSheet player;

public:
    // Construtor que inicializa o player com os valores de level, name, species e classes
    PlayerSheetHolder() 
        : player(level, name, species_, classes_) {}


    // Métodos para atualizar os atributos e o player
    void defineLevel(int receivedlevel){
        level = receivedlevel;
        player = TechnicalSheet(level, name, species_, classes_);
    }

    void defineName(std::string receivedname){
        name = receivedname;
        player = TechnicalSheet(level, name, species_, classes_);
    }

    void defineSpecies(Species receivedspecies){
        species_ = receivedspecies;
        player = TechnicalSheet(level, name, species_, classes_);
    }

    void defineClasses(Classes receivedclasses){
        classes_ = receivedclasses;
        player = TechnicalSheet(level, name, species_, classes_); 
    }

   
    //Método gett para player, não permite alterações em player
    const TechnicalSheet& getPlayerConst() const {
    return player;
    //Não sei se terá aplicação viável o encapsulamento lógico em TechnicalSheet já é forte o baste
    }

    //Método get que permite alterar o objeto player
    TechnicalSheet& getPlayer() {
    return player;  
}

}
