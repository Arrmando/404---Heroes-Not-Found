#include "./include/viewCombate.hpp"
#include <iostream>

CombatScreen::CombatScreen() {

    desktop = sf::VideoMode::getDesktopMode();

    windowWidth = 1160;
    windowHeight = 720;
    posX = (desktop.width - windowWidth) / 2;
    posY = (desktop.height - windowHeight) / 2;
    // Abre a Janela
    window.create(sf::VideoMode(windowWidth, windowHeight), "Hora do Combate!!!");
    window.setPosition(sf::Vector2i(posX, posY));

    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        // Handle font loading error
    }
    
    // adiciona texto 
    bossName.setFont(font);
    bossName.setPosition(25.0f, 25.0f);
    bossName.setCharacterSize(20);
    bossName.setFillColor(sf::Color::Black);
    bossName.setString("LARGATIXA COMUNA Lv: 1313");

    playerName.setFont(font);
    playerName.setPosition(785.0f, 25.0f);
    playerName.setCharacterSize(20);
    playerName.setFillColor(sf::Color::Black);
    playerName.setString("Fachinelli Lv: 1000");

    aliadoName1.setFont(font);
    aliadoName1.setPosition(785.0f, 135.0f);
    aliadoName1.setCharacterSize(20);
    aliadoName1.setFillColor(sf::Color::Black);
    aliadoName1.setString("Barrosao Lv: 500");

    aliadoName2.setFont(font);
    aliadoName2.setPosition(785.0f, 245.0f);
    aliadoName2.setCharacterSize(20);
    aliadoName2.setFillColor(sf::Color::Black);
    aliadoName2.setString("Armando Lv: 200");

    aliadoName3.setFont(font);
    aliadoName3.setPosition(785.0f, 355.0f);
    aliadoName3.setCharacterSize(20);
    aliadoName3.setFillColor(sf::Color::Black);
    aliadoName3.setString("Campello Lv: 100");

    
    // Imagem de Fundo
    if (!backgroundTexture.loadFromFile("assets/images/dragao-verde.png")) { 
    throw std::runtime_error("Erro ao carregar o arquivo PNG de fundo!");
    }
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0.0f, 100.0f);
    

    viewModel = new ViewModelCombate();
    if (viewModel == nullptr) {
        std::cerr << "Erro: Falha ao instanciar ViewModelCombate!" << std::endl;
    }

    // botões
    attackButton = new Button(0.0f, 100.0f, 760.0f, 620.0f, sf::Color::Transparent, "", font, 0);
    specialButton1 = new Button(1060.0f, 140.0f, 75.0f, 50.0f, sf::Color::Black, "X", font, 30, true, 2);
    specialButton2 = new Button(1060.0f, 250.0f, 75.0f, 50.0f, sf::Color::Black, "X", font, 30, true, 2);
    specialButton3 = new Button(1060.0f, 360.0f, 75.0f, 50.0f, sf::Color::Black, "X", font, 30, true, 2);
    escapeButton = new Button(785.0f, 595.0f, 350.0f, 100.0f, sf::Color::Red, "FUGIR", font, 30);

    bossInitialLife = viewModel->getHealthBoss();
    playerInitialLife = viewModel->getHealthPlayer();

    // Barra de vida
    lifeBossBar = new lifeBar(25.0f, 55.0f, 560.0f, 25.0f, sf::Color::Red, bossInitialLife, viewModel->getHealthBoss());
    lifePlayerBar = new lifeBar(785.0f, 55.0f, 350.0f, 25.0f, sf::Color::Blue, playerInitialLife, viewModel->getHealthPlayer());
    lifeAliado1 = new lifeBar(785.0f, 165.0f, 250.0f, 25.0f, sf::Color::Green, 100, 100);
    lifeAliado2 = new lifeBar(785.0f, 275.0f, 250.0f, 25.0f, sf::Color::Green, 100, 100);
    lifeAliado3 = new lifeBar(785.0f, 385.0f, 250.0f, 25.0f, sf::Color::Green, 100, 100);

    // Área lateral
    area.setSize(sf::Vector2f(400.0f, 720.0f)); 
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
    delete specialButton1;
    delete specialButton2;
    delete specialButton3;
    delete escapeButton;
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
            if (specialButton1->isClicked(sf::Mouse::getPosition(window))) {
                viewModel->handleSpecial(); 
                
            }
            if (specialButton2->isClicked(sf::Mouse::getPosition(window))) {
                viewModel->handleSpecial();
            }
            if (specialButton3->isClicked(sf::Mouse::getPosition(window))) {
                viewModel->handleSpecial();
            }
            if (escapeButton->isClicked(sf::Mouse::getPosition(window))) {
                window.close();
                viewModel->handleEscapeButton();
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
    specialButton1->setColorHover(hoverColor, sf::Color::Magenta, window);
    specialButton2->setColorHover(hoverColor, sf::Color::Magenta, window);
    specialButton3->setColorHover(hoverColor, sf::Color::Magenta, window);
    escapeButton->setColorHover(hoverColor, sf::Color::Red, window);

    window.draw(area); 
    window.draw(areaTop);

    lifeBossBar->draw(window);
    lifePlayerBar->draw(window);
    lifeAliado1->draw(window);
    lifeAliado2->draw(window);
    lifeAliado3->draw(window);

    window.draw(bossName);
    window.draw(playerName);
    window.draw(aliadoName1);
    window.draw(aliadoName2);
    window.draw(aliadoName3);

    window.draw(backgroundSprite);

    attackButton->draw(window);
    specialButton1->draw(window);
    specialButton2->draw(window);
    specialButton3->draw(window);
    escapeButton->draw(window);
}
