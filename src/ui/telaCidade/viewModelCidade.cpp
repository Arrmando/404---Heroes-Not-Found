#include "./include/viewModelCidade.hpp"       
#include "../telaBar/viewBar.cpp"       
#include <SFML/Graphics.hpp>
#include <memory>

// Gerenciador de janela única
std::unique_ptr<sf::RenderWindow> currentWindow = nullptr;

void fecharJanelaAtual() {
    if (currentWindow && currentWindow->isOpen()) {
        currentWindow->close();
        currentWindow.reset(); // Libera o recurso
    }
}



void mudarParaBar() {
    fecharJanelaAtual();

    currentWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(640, 480), "Bar");
    Bar(*currentWindow); // Passa a nova janela para o bar
}


