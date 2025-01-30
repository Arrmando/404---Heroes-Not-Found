#ifndef LOJA_HPP
#define LOJA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "../../components/include/Button.hpp"
#include "viewModelLoja.hpp"

class Loja{
public:
    Loja();
    void run();
    void handleEvents();
    void update();
    void render();

private:
    std::unique_ptr<Button> comprarArma;
    std::unique_ptr<Button> comprarArmadura;
    sf::RenderWindow telaLoja;
    std::unique_ptr<Button> retornar;
    sf::Font font;
    sf::Font fontSetas;
    sf::Texture lojaTexture;
    sf::Sprite lojaSprite;

    int money = 10;
    int precoArma = 3;
    int precoArmadura = 2;
    sf::Text moneyText;
    sf::Text armaText;
    sf::Text armaduraText;
<<<<<<< HEAD

=======
    ViewModelLoja* viewModel;
>>>>>>> origin/main
    void updateMoneyText();
    void updateArmaText();
    void updateArmaduraText();
};

<<<<<<< HEAD
#endif // LOJA_HPP
=======
#endif
>>>>>>> origin/main
