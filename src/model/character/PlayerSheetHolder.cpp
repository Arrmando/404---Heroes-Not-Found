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
        player.setLevel(level);  // Atualiza o nível diretamente no objeto player
    }

    void defineName(const std::string& receivedname){
        name = receivedname;
        player.setName(name);  // Atualiza o nome diretamente no objeto player
    }

    void defineSpecies(Species receivedspecies){
        species_ = receivedspecies;
        player.setSpecies(species_);  // Atualiza a espécie diretamente no objeto player
    }

    void defineClasses(Classes receivedclasses){
        classes_ = receivedclasses;
        player.setClasses(classes_);  // Atualiza a classe diretamente no objeto player
    }

    // Método get para player, não permite alterações em player

    const TechnicalSheet& getPlayerConst() const {
        return player;
    }

    // Método get que permite alterar o objeto player

    TechnicalSheet& getPlayer() {
        return player;  
    }
};