#ifndef LOJA_HPP
#define LOJA_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "../../components/include/Button.hpp"


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
    sf::Font font;
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
>>>>>>> 7ae47cc01ff71a13231a93e101df0927ef436e45

    void updateMoneyText();
    void updateArmaText();
    void updateArmaduraText();
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 7ae47cc01ff71a13231a93e101df0927ef436e45
