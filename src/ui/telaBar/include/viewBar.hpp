#ifndef BAR_HPP
#define BAR_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "../../Components/include/Button.hpp"

class Bar {
public:
    Bar();
    void run();
    void handleEvents();
    void update();
    void render();
    

private:
    std::unique_ptr<Button> comprarMercenario;
    sf::RenderWindow telaBar;
    sf::Font font;
    sf::Texture barTexture;
    sf::Sprite barSprite;
    
    int money = 10;
    int precoMecenario = 3;
    sf::Text moneyText;
    sf::Text mercenarioText;

    void updateMoneyText();
    void updateMercenarioText();
};

#endif
