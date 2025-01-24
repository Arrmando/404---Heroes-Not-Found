#ifndef Sobre_HPP
#define Sobre_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include "../../components/include/Button.hpp"
#include "viewModelSobre.hpp"

class Sobre {
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::Text titleText;
    sf::Text nomeText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::unique_ptr<Button> returnButton;

    std::unique_ptr<SobreViewModel> viewModel;

public:
    Sobre();
    void handleEvents();
    void render();
    void run();
};

#endif