#include "./include/viewLoja.hpp"
#include "./include/viewModelLoja.hpp"

Loja::Loja()
    : telaLoja(sf::VideoMode(900, 600), "Loja") {
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!fontSetas.loadFromFile("assets/fonts/setas.ttf")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!lojaTexture.loadFromFile("assets/images/loja.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }
    viewModel = new ViewModelLoja();
    lojaSprite.setTexture(lojaTexture);
    lojaSprite.setScale(0.8f, 0.7f);

    comprarArma = std::make_unique<Button>(350, 400, 400, 50, sf::Color::Yellow, "Comprar Arma", font, 30);
    comprarArmadura = std::make_unique<Button>(350, 300, 400, 50, sf::Color::Yellow, "Comprar Armadura", font, 30);
    retornar = std::make_unique<Button>(50, 50, 75, 50, sf::Color::White, "9", fontSetas, 20, true );

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(10, 10);

    updateMoneyText(); // Atualiza o texto do contador
}

void Loja::update() { 
    updateMoneyText();  // Atualiza o texto do dinheiro
    updateArmaText();  // Atualiza o texto da arma
    updateArmaduraText(); // Atualiza o texto da armadura
}

void Loja::updateArmaText() {
    armaText.setString("Espada de Fogo");
}

void Loja::updateArmaduraText() {
    armaduraText.setString("Armadura de Diamante");
}

void Loja::updateMoneyText() {                                                                                                                                     
    moneyText.setString("Dinheiro: " + std::to_string(money) + " R$");
}

void Loja::handleEvents() {
    sf::Event event;
    while (telaLoja.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaLoja.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaLoja);

            if (comprarArma->isClicked(mousePos) && money >= precoArma) {
                money -= precoArma;
                updateMoneyText();
            }
            if (comprarArmadura->isClicked(mousePos) && money >= precoArmadura) {
                money -= precoArmadura;
                updateMoneyText();
            }
            if (retornar->isClicked(mousePos)) {
                telaLoja.close();
                viewModel->mudarParaCidade();
            }
        }
    }
}

void Loja::run() {
    while (telaLoja.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Loja::render() {
    sf::Color hoverColor = sf::Color(200, 200, 200); // Example hover color
    sf::Color defaultColor = sf::Color(128, 128, 128); // Default color

    // Update button colors based on hover state
    comprarArma->setColorHover(hoverColor, defaultColor, telaLoja);
    comprarArmadura->setColorHover(hoverColor, defaultColor, telaLoja);

    telaLoja.clear();
    telaLoja.draw(lojaSprite);
    comprarArma->draw(telaLoja);
    comprarArmadura->draw(telaLoja);
    retornar->draw(telaLoja);
    telaLoja.draw(moneyText);
    telaLoja.draw(armaText);
    telaLoja.draw(armaduraText);
    telaLoja.display();
}