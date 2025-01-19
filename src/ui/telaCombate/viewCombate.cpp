#include "viewCombate.hpp"

CombatScreen::CombatScreen() {
    // Abre a Janela
    window.create(sf::VideoMode(960, 720), "Hora do Combate!!!");

    if (!font.loadFromFile("assets/fonts/pixel-arial-11.TTF")) {
        // Handle font loading error
    }

    // Define os botões
    attackButton = new Button(0.0f, 100.0f, 760.0f, 620.0f, sf::Color::Transparent, "", font, 0);
    specialButton = new Button(300.0f, 500.0f, 150.0f, 50.0f, sf::Color(128, 128, 128), "Especial", font, 30);

    // Barra de vida
    lifeBossBar = new lifeBar(25.0f, 55.0f, 560.0f, 25.0f, sf::Color::Red, 100.0f, 80.0f);

    // Inicia o ViewModel
    viewModel = new ViewModelCombate();

    // Área lateral
    area.setSize(sf::Vector2f(200.0f, 720.0f)); 
    area.setFillColor(sf::Color(128, 128, 128)); 
    area.setPosition(760.0f, 0.0f);
    area.setOutlineThickness(2);
    area.setOutlineColor(sf::Color::Black);

    // Área superior
    areaTop.setSize(sf::Vector2f(758.0f, 100.0f));
    areaTop.setFillColor(sf::Color(128, 128, 128));
    areaTop.setPosition(0.0f, 0.0f);
    areaTop.setOutlineThickness(2);
    areaTop.setOutlineColor(sf::Color::Black);
}

CombatScreen::~CombatScreen() {
    delete attackButton;
    delete specialButton;
    delete viewModel;
}

void CombatScreen::run() {
    while (window.isOpen()) {
        handleEvents();
        window.clear();
        render();
        window.display();
    }
}

void CombatScreen::handleEvents() {
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

void CombatScreen::render() {
    // Set hover colors
    sf::Color hoverColor = sf::Color(200, 200, 200); // Example hover color
    sf::Color defaultColor = sf::Color(128, 128, 128); // Default color
    sf::Color attackColor = sf::Color(200, 200, 200, 10);

    // Update button colors based on hover state
    attackButton->setColorHover(hoverColor, attackColor, window);
    specialButton->setColorHover(hoverColor, defaultColor, window);

    attackButton->draw(window);
    specialButton->draw(window);

    window.draw(area); 
    window.draw(areaTop);

    lifeBossBar->draw(window);
}
