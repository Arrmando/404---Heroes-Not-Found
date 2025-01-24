#ifndef VIEW_COMBATE_HPP
#define VIEW_COMBATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../components/include/Button.hpp"
#include "../../components/include/lifeBar.hpp"
#include "viewModelCombate.hpp"

class CombatScreen {
public:
    CombatScreen();  // Construtor
    ~CombatScreen(); // Destrutor

    void run();    
    void handleEvents();
    void render();   

private:
    sf::RenderWindow window;
    sf::Font font;

    ViewModelCombate* viewModel;

    Button* attackButton;  
    Button* specialButton1; 
    Button* specialButton2;
    Button* specialButton3;
    Button* escapeButton;

    lifeBar* lifeBossBar;  
    lifeBar* lifePlayerBar;

    lifeBar* lifeAliado1;
    lifeBar* lifeAliado2;
    lifeBar* lifeAliado3;

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    float bossInitialLife; 
    float playerInitialLife;

    sf::VideoMode desktop;
    int posX, posY, windowWidth, windowHeight;
    
    sf::RectangleShape area;    
    sf::RectangleShape areaTop; 

    sf::Text bossName;
    sf::Text playerName;
    sf::Text aliadoName1;
    sf::Text aliadoName2;
    sf::Text aliadoName3;
};

#endif