#ifndef VIEW_COMBATE_HPP
#define VIEW_COMBATE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Components/include/Button.hpp"
#include "../Components/include/lifeBar.hpp"
#include "viewModelCombate.hpp"

class CombatScreen {
public:
    CombatScreen();
    ~CombatScreen();
    void run();

private:
    sf::RenderWindow window;
    Button* attackButton; 
    Button* specialButton; 
    lifeBar* lifeBossBar;
    sf::Font font;
    ViewModelCombate* viewModel; 
    sf::RectangleShape area;
    sf::RectangleShape areaTop;

    void handleEvents();
    void render();
};

#endif
