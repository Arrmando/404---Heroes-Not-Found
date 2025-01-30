#ifndef BAR_HPP
#define BAR_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../../components/include/Button.hpp"
#include "../../components/include/timer.hpp"
#include "viewModelBar.hpp"
#include "../../components/include/Dracmas.hpp"

class Bar {
public:
    Bar();
    void run();
    void handleEvents();
    void update();
    void render();

private:
    Timer timer;
    sf::Clock gameClock;

    std::unique_ptr<Button> comprarMercenario;
    std::unique_ptr<Button> retornar;
    sf::RenderWindow telaBar;
    sf::Font font;
    sf::Texture barTexture;
    sf::Sprite barSprite;

    const int precoMecenario = 3; // Preço fixo do mercenário
    sf::Text moneyText;
    ViewModelBar* viewModel;

    void updateMoneyText();
};
#endif
