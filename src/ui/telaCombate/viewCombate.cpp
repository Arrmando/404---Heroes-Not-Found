#include "./include/viewCombate.hpp"
#include <iostream>

CombatScreen::CombatScreen() {

    desktop = sf::VideoMode::getDesktopMode();

    windowWidth = 960;
    windowHeight = 720;
    posX = (desktop.width - windowWidth) / 2;
    posY = (desktop.height - windowHeight) / 2;
    // Abre a Janela
    window.create(sf::VideoMode(windowWidth, windowHeight), "Hora do Combate!!!");
    window.setPosition(sf::Vector2i(posX, posY));

    if (!font.loadFromFile("assets/fonts/pixel-arial-11.TTF")) {
        // Handle font loading error
    }
    
    // adiciona texto 
    bossName.setFont(font);
    bossName.setPosition(25.0f, 25.0f);
    bossName.setCharacterSize(20);
    bossName.setFillColor(sf::Color::Black);
    bossName.setString("DRAGÃO BRABO Lv: 400");

    playerName.setFont(font);
    playerName.setPosition(785.0f, 25.0f);
    playerName.setCharacterSize(20);
    playerName.setFillColor(sf::Color::Black);
    playerName.setString("Fachinelli Lv: 1000");
    
    // Imagem de Fundo
    if (!backgroundTexture.loadFromFile("assets/images/dragao-verde.png")) { 
    throw std::runtime_error("Erro ao carregar o arquivo PNG de fundo!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.0f, 100.0f);
    
    // Inicia o ViewModel
    viewModel = new ViewModelCombate();
    if (viewModel == nullptr) {
        std::cerr << "Erro: Falha ao instanciar ViewModelCombate!" << std::endl;
    // Tratar o erro adequadamente
    }

    // Define os botões
    attackButton = new Button(0.0f, 100.0f, 760.0f, 620.0f, sf::Color::Transparent, "", font, 0);
    specialButton = new Button(785.0f, 500.0f, 150.0f, 50.0f, sf::Color::Magenta, "Especial", font, 30);

    bossInitialLife = viewModel->getHealthBoss();
    playerInitialLife = viewModel->getHealthPlayer();

    // Barra de vida
    lifeBossBar = new lifeBar(25.0f, 55.0f, 560.0f, 25.0f, sf::Color::Red, bossInitialLife, viewModel->getHealthBoss());
    lifePlayerBar = new lifeBar(785.0f, 55.0f, 150.0f, 25.0f, sf::Color::Blue, playerInitialLife, viewModel->getHealthPlayer());

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
        viewModel->handleAttackSpeed();
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
                viewModel->handleAttack(); 
            }
            if (specialButton->isClicked(sf::Mouse::getPosition(window))) {
                viewModel->handleSpecial(); 
                viewModel->handleBossAttack();
            }
        }
    }
}


void CombatScreen::render() {
    // Set hover colors
    sf::Color hoverColor = sf::Color(200, 200, 200); // Example hover color
    sf::Color defaultColor = sf::Color(128, 128, 128); // Default color
    sf::Color attackColor = sf::Color(128, 128, 128, 50);

    // Barra de vida atualiza
    lifeBossBar->setHealth(viewModel->getHealthBoss());
    lifePlayerBar->setHealth(viewModel->getHealthPlayer());

    attackButton->setColorHover(attackColor, sf::Color::Transparent, window);
    specialButton->setColorHover(hoverColor, defaultColor, window);

    window.draw(area); 
    window.draw(areaTop);

    lifeBossBar->draw(window);
    lifePlayerBar->draw(window);

    window.draw(bossName);
    window.draw(playerName);

    window.draw(backgroundSprite);

    attackButton->draw(window);
    specialButton->draw(window);
}
