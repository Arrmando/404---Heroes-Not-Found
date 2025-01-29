#include "./include/viewBar.hpp"
#include "./include/viewModelBar.hpp"

Bar::Bar(TechnicalSheet* character)
    : telaBar(sf::VideoMode(900, 600), "Bar"),
      timer(font, 350, 250, 50),
      viewModel(std::make_unique<ViewModelBar>(character)) // Inicializa o ViewModelBar com o personagem
{
    if (!font.loadFromFile("assets/fonts/PIXEARG_.TTF")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!fontSetas.loadFromFile("assets/fonts/setas.ttf")) {
        throw std::runtime_error("Erro ao carregar a fonte!");
    }
    if (!barTexture.loadFromFile("assets/images/bar.jpg")) {
        throw std::runtime_error("Erro ao carregar a imagem de fundo!");
    }

    timer.start(120); // Inicia o timer com 2 minutos
    barSprite.setTexture(barTexture);
    barSprite.setScale(1.5f, 1.8f);

    comprarMercenario = std::make_unique<Button>(350, 400, 200, 100, sf::Color::Yellow, "Comprar", font, 30, true, 2.0);
    retornar = std::make_unique<Button>(50, 50, 75, 50, sf::Color::White, "9", fontSetas, 20, true);

    moneyText.setFont(font);
    moneyText.setCharacterSize(24);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setPosition(10, 10);

    updateMoneyText(); // Atualiza o texto inicial do dinheiro
}

void Bar::update() {
    sf::Time deltaTime = gameClock.restart();
    timer.update(deltaTime);
    updateMoneyText();
    updateMercenarioText();
}

void Bar::updateMoneyText() {
    moneyText.setString("Dinheiro: " + std::to_string(viewModel->getMoney()) + " R$");
}

void Bar::updateMercenarioText() {
    mercenarioText.setString("ORK Guerreiro level: 15");
}

void Bar::handleEvents() {
    sf::Event event;
    while (telaBar.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            telaBar.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(telaBar);

            if (comprarMercenario->isClicked(mousePos) && viewModel->getMoney() >= precoMecenario) {
                viewModel->comprarMercenario(precoMecenario);
                updateMoneyText();
            }
            if (retornar->isClicked(mousePos)) {
                telaBar.close();
                viewModel->mudarParaCidade();
            }
        }
    }
}

void Bar::run() {
    while (telaBar.isOpen()) {
        handleEvents();
        update();
        render();
    }
}

void Bar::render() {
    telaBar.clear();
    telaBar.draw(barSprite);
    comprarMercenario->draw(telaBar);
    retornar->draw(telaBar);
    timer.draw(telaBar);
    telaBar.draw(moneyText);
    telaBar.draw(mercenarioText);
    telaBar.display();
}
