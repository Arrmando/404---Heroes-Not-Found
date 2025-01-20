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
    Button* specialButton; 
    lifeBar* lifeBossBar;  
    lifeBar* lifePlayerBar;

    float bossInitialLife; 
    sf::RectangleShape area;    
    sf::RectangleShape areaTop; 
};

#endif