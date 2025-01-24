#ifndef BAR_HPP
#define BAR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "../../components/include/Button.hpp"
#include "../../components/include/timer.hpp"
#include "viewModelBar.hpp"

class Bar {
public:
    Bar();
    void run();
    void handleEvents();
    void update();
    void render();

private:
    Timer timer;                      // Timer como atributo da classe
    sf::Clock gameClock;              // Relógio para calcular o deltaTime

    std::unique_ptr<Button> comprarMercenario;
    std::unique_ptr<Button> retornar;
    sf::RenderWindow telaBar;
    sf::Font font;
    sf::Font fontSetas;
    sf::Texture barTexture;
    sf::Sprite barSprite;

    int money = 10;
    int precoMecenario = 3;
    sf::Text moneyText;
    sf::Text mercenarioText;
    ViewModelBar* viewModel;

    void updateMoneyText();
    void updateMercenarioText();
};

#endif
