#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Components/include/Button.hpp"
#include "viewModelCombate.hpp" // Include the view model header

class CombatScreen {
public:
    CombatScreen() {
        // Abre a Janela
        window.create(sf::VideoMode(800, 600), "Combat Screen");

        if (!font.loadFromFile("assets/fonts/pixel-arial-11.TTF")) {
          
        }

        // Define os botões
        attackButton = new Button(100.0f, 500.0f, 150.0f, 50.0f, sf::Color(128, 128, 128), "Atacar", font, 30);
        specialButton = new Button(300.0f, 500.0f, 150.0f, 50.0f, sf::Color(128, 128, 128), "Especial", font, 30);

        // Inicia o ViewModel
        viewModel = new ViewModelCombate();
    }

    ~CombatScreen() {
        delete attackButton;
        delete specialButton;
        delete viewModel; // Destrutor
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            window.clear();
            render();
            window.display();
        }
    }

private:
    sf::RenderWindow window;
    Button* attackButton; 
    Button* specialButton; 
    sf::Font font;
    ViewModelCombate* viewModel; 

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // Handle button clicks
            if (event.type == sf::Event::MouseButtonPressed) {
                if (attackButton->isClicked(sf::Mouse::getPosition(window))) {
                    viewModel->handleAttack(); // Call the attack method in the view model
                }
                if (specialButton->isClicked(sf::Mouse::getPosition(window))) {
                    viewModel->handleSpecial(); // Call the special method in the view model
                }
            }
        }
    }

    void render() {
        attackButton->draw(window);
        specialButton->draw(window);
        // Draw more elements as needed
    }
};

int main() {
    CombatScreen combatScreen;
    combatScreen.run();
    return 0;
}
