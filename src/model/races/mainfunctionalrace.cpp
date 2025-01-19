// Código para criar instâncias das raças e interagir com elas através da interface (racesinterface.h)

#include <iostream>
#include <vector>
#include <memory>
#include "raceIncubator.hpp"

int main() {
    // Vetor para armazenar diferentes raças tanto as criadas já no sistemas quanto futuras, espero que rode direito
    std::vector<std::unique_ptr<interfaceRace>> races;

    // Criar instâncias de cada raça usando a incubadora
    races.emplace_back(raceIncubator::createRace(raceIncubator::RaceType::Demihuman));
    races.emplace_back(raceIncubator::createRace(raceIncubator::RaceType::Fairy));
    races.emplace_back(raceIncubator::createRace(raceIncubator::RaceType::Giant));

    // Iterar sobre as raças e executar seus métodos
    for(auto& race : races) {
        if(race) { // Verificar se a raça foi criada com sucesso
            std::cout << "\n=== " << race->getRaceName() << " ===\n";
            race->onStart();
            race->setDefaultAttributes();
            race->raceSpecialTrait();
            race->onDestroy();
        }
    }

    return 0;
}