#ifndef SOBRE_HPP
#define SOBRE_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "../../components/include/Button.hpp"
#include "viewModelSobre.hpp"

class Sobre {
private:
    // Janela e elementos gráficos
    sf::RenderWindow window;
    sf::Font font;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    
    // Elementos de texto
    sf::Text titleText;
    sf::Text frontendTitleText;
    sf::Text backendTitleText;
    sf::Text nomeText;       // Para nomes FrontEnd
    sf::Text backendText;    // Para nomes BackEnd

    // Botão e ViewModel
    std::unique_ptr<Button> returnButton;
    std::unique_ptr<SobreViewModel> viewModel;

    // Listas de nomes ordenados
    std::vector<std::string> frontendNames;
    std::vector<std::string> backendNames;

public:
    Sobre();
    void handleEvents();
    void render();
    void run();
};

#endif