#ifndef BAR_HPP
#define BAR_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../../components/include/Button.hpp"
#include "../../components/include/timer.hpp"
#include "viewModelBar.hpp"

class Bar {
public:
    Bar(TechnicalSheet* character); // Recebe o personagem principal como argumento
    void run();
    void handleEvents();
    void update();
    void render();

private:
    std::unique_ptr<ViewModelBar> viewModel; // Gerencia o ViewModelBar

    Timer timer;
    sf::Clock gameClock;

    std::unique_ptr<Button> comprarMercenario;
    std::unique_ptr<Button> retornar;
    sf::RenderWindow telaBar;
    sf::Font font;
    sf::Font fontSetas;
    sf::Texture barTexture;
    sf::Sprite barSprite;

    int precoMecenario = 3;
    sf::Text moneyText;
    sf::Text mercenarioText;

    void updateMoneyText();
    void updateMercenarioText();
};

#endif
