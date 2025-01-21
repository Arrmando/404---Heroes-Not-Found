#include "./include/viewBar.hpp"
#include "./include/viewModel.hpp"
#include "../telaCidade/include/viewCidade.hpp"

Bar::Bar()
    : telaBar(sf::VideoMode(900, 600), "Bar"),
    timer(font, 350, 250, 50){
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!barTexture.loadFromFile("assets/images/bar.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }
    
    
    timer.start(120); // Inicia o timer com 2 minutos

    sf::Clock clock;

    barSprite.setTexture(barTexture);
    barSprite.setScale(0.6f, 0.6f);

    comprarMercenario = std::make_unique<Button>(350, 400, 200, 100, sf::Color::Yellow, "Comprar", font, 30);
    retornar = std::make_unique<Button>(50, 50, 100, 100, sf::Color::White, "Return", font, 20);
    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(10, 10);

    updateMoneyText(); // Atualiza o texto do contador
 }
 void Bar::update() {
    sf::Time deltaTime = gameClock.restart();  // Obtém o tempo passado desde o último quadro
    timer.update(deltaTime);  // Passa o deltaTime para atualizar o timer
    updateMoneyText();  // Atualiza o texto do dinheiro
    updateMercenarioText();  // Atualiza o texto do mercenário
}

void Bar::updateMercenarioText() {
    mercenarioText.setString("ORK Guerreiro level: 15");
}
void Bar::updateMoneyText() {                                                                                                                                     
    moneyText.setString("Dinheiro: " + std::to_string(money) + " R$");
}
void Bar::handleEvents() {
    sf::Event event;
    while (telaBar.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaBar.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaBar);

            if (comprarMercenario->isClicked(mousePos) && money >= precoMecenario) {
                updateMoneyText(); // Atualiza o texto do contador
            }
            if (retornar->isClicked(mousePos)) {
                telaBar.close();
                Cidade cidade;
                cidade.run();
                // Atualiza o texto do contador
            }
        }
    }
}

void Bar::run() {
    while (telaBar.isOpen()) {
        handleEvents();
        render();
        update();
    }
}

void Bar::render() {
    sf::Color hoverColor = sf::Color(200, 200, 200); // Example hover color
    sf::Color defaultColor = sf::Color(128, 128, 128); // Default color
    sf::Color attackColor = sf::Color(200, 200, 200, 10);

    // Update button colors based on hover state
    comprarMercenario->setColorHover(hoverColor, defaultColor, telaBar);

    telaBar.clear();
    telaBar.draw(barSprite);// Exibe o texto do dinheiro
    comprarMercenario->draw(telaBar);
    retornar->draw(telaBar);
    timer.draw(telaBar);
    telaBar.draw(moneyText);
    telaBar.draw(mercenarioText);
    telaBar.display();
}