#include "./include/lifeBar.hpp"

lifeBar::lifeBar(float x, float y, float width, float height, const sf::Color& fillColor, float maxLife, float currentLife) {
    this->maxLife = maxLife;     // Atribui a vida máxima do modelo
    this->currentLife = currentLife; 
    isFlashing = false;   // Define se está piscando

    lifeWidth = width * (currentLife / maxLife); // Define a largura da barra de vida com base na % atual

    // Inicializa a barra de vida
    lifeFill.setSize(sf::Vector2f(lifeWidth, height));
    lifeFill.setFillColor(fillColor);
    lifeFill.setPosition(x, y);

    // Inicializa o fundo
    lifeBack.setSize(sf::Vector2f(width, height));
    lifeBack.setFillColor(sf::Color::Black);
    lifeBack.setOutlineThickness(2);
    lifeBack.setOutlineColor(sf::Color::Black);
    lifeBack.setPosition(x, y);
}

void lifeBar::draw(sf::RenderWindow& window) {
    window.draw(lifeBack);  // Desenha o fundo da barra
    window.draw(lifeFill);  // Desenha a barra de vida atual
}

void lifeBar::setHealth(float health) {
    // Atualiza a vida atual
    currentLife = health;
    
    // Garantir que a vida não seja menor que 0 ou maior que a vida máxima
    if (currentLife < 0) currentLife = 0;
    if (currentLife > maxLife) currentLife = maxLife;

    // Atualiza a largura da barra de vida com base na vida atual
    lifeWidth = lifeBack.getSize().x * (currentLife / maxLife);
    lifeFill.setSize(sf::Vector2f(lifeWidth, lifeFill.getSize().y));  // Atualiza a largura da barra de vida
}
