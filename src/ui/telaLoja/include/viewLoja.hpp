#ifndef LOJA_HPP
#define LOJA_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../../components/include/Button.hpp"
#include "viewModelLoja.hpp"
#include "../../components/include/Dracmas.hpp"

class Loja {
public:
    Loja();
    void run();
    void handleEvents();
    void update();
    void render();

private:
    std::unique_ptr<Button> comprarArma;
    std::unique_ptr<Button> comprarArmadura;
    std::unique_ptr<Button> retornar;
    sf::RenderWindow telaLoja;
    sf::Font font;
    sf::Texture lojaTexture;
    sf::Sprite lojaSprite;

    const int precoArma = 3;      // Preço fixo da arma
    const int precoArmadura = 2;  // Preço fixo da armadura
    sf::Text moneyText;
    sf::Text armaText;
    sf::Text armaduraText;
    ViewModelLoja* viewModel;

    void updateMoneyText();
    void updateArmaText();
    void updateArmaduraText();
};
#endif