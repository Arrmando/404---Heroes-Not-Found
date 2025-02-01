#ifndef VIEW_COMBATE_HPP
#define VIEW_COMBATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../components/include/Button.hpp"
#include "../../components/include/lifeBar.hpp"
#include "viewModelCombate.hpp"
#include "../../components/include/Dracmas.hpp"
#include "viewCidade.hpp"

class CombatScreen {
public:
    CombatScreen();
    ~CombatScreen();

    void run();
    void handleEvents();
    void render();

private:
    void checkBossDefeat();
    void updateLifeBars();
    void handleMouseClick(const sf::Vector2i& mousePos);

    sf::RenderWindow window;
    sf::Font font;
    ViewModelCombate* viewModel;

    // Elementos de UI
    Button* attackButton;
    Button* specialButton1;
    Button* specialButton2;
    Button* specialButton3;
    Button* escapeButton;

    // Barras de vida
    lifeBar* lifeBossBar;
    lifeBar* lifePlayerBar;
    lifeBar* lifeAliado1;
    lifeBar* lifeAliado2;
    lifeBar* lifeAliado3;

    // Elementos gráficos
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    sf::RectangleShape area;
    sf::RectangleShape areaTop;

    // Textos
    sf::Text bossName;
    sf::Text playerName;
    sf::Text aliadoName1;
    sf::Text aliadoName2;
    sf::Text aliadoName3;

    // Estado do jogo
    float bossInitialLife;
    float playerInitialLife;
    sf::VideoMode desktop;
    int posX, posY, windowWidth, windowHeight;
};

#endif