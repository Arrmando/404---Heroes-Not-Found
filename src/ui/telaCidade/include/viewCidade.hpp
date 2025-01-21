#ifndef CIDADE_HPP
#define CIDADE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "viewModelCidade.hpp"
#include "../../components/include/Button.hpp"

class Cidade {
public:
    Cidade();
    void run();
    void handleEvents();
    void update();
    void render();
    
private:
    std::unique_ptr<Button> irLoja;
    std::unique_ptr<Button> irBar;
    std::unique_ptr<Button> irCombate;
    std::unique_ptr<Button> irMenu;
    sf::RenderWindow telaCidade;
    sf::Font font;
    sf::Texture cidadeTexture;
    sf::Sprite cidadeSprite;
    ViewModelCidade* viewModel;  
    
    int money = 10;
    sf::Text moneyText;

    void updateMoneyText();
};

#endif
