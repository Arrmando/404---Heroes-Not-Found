#include "./include/Button.hpp"

Button::Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label, sf::Font& font, float fontSize, bool isCircle) {
    if (isCircle) {
        circleShape.setRadius(width / 2.f); // Faz o botão circular, com raio baseado na largura
        circleShape.setPosition(x + width / 2.f, y + height / 2.f); // Centraliza a forma
        circleShape.setFillColor(color);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::Black);

        // Centraliza o texto no botão circular
        text.setPosition(
            x + (width - text.getGlobalBounds().width) / 2.f,
            y + (height - text.getGlobalBounds().height) / 2.f - text.getLocalBounds().top
        );
    } else {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        shape.setFillColor(color);

        text.setFont(font);
        text.setString(label);
        text.setCharacterSize(fontSize);
        text.setFillColor(sf::Color::Black);

        // Centraliza o texto no botão retangular
        text.setPosition(
            x + (width - text.getGlobalBounds().width) / 2.f,
            y + (height - text.getGlobalBounds().height) / 2.f - text.getLocalBounds().top
        );
    }
}

void Button::setColor(const sf::Color& color) {
    if (circleShape.getRadius() > 0) {
        circleShape.setFillColor(color);  
    } else {
        shape.setFillColor(color);  
    }
}

void Button::setColorHover(const sf::Color& hoverColor, const sf::Color& defaultColor, sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    if (isHover(mousePos)) {
        setColor(hoverColor);
    } else {
        setColor(defaultColor);
    }
}

void Button::draw(sf::RenderWindow& window) {
    if (circleShape.getRadius() > 0) {
        window.draw(circleShape); // Desenha o botão circular
    } else {
        window.draw(shape); // Desenha o botão retangular
    }
    window.draw(text); // Desenha o texto em ambos os casos
}

bool Button::isClicked(const sf::Vector2i& mousePos) {
    if (circleShape.getRadius() > 0) {
        return circleShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    } else {
        return shape.getGlobalBounds().contains(mousePos.x, mousePos.y);
    }
}

bool Button::isHover(const sf::Vector2i& mousePos) const {
    if (circleShape.getRadius() > 0) {
        return circleShape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    } else {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }
}

void Button::setText(const std::string& label) {
    text.setString(label);

    // Recalcula a posição para centralizar o texto no botão
    if (circleShape.getRadius() > 0) {
        text.setPosition(
            circleShape.getPosition().x + (circleShape.getRadius() - text.getGlobalBounds().width) / 2.f,
            circleShape.getPosition().y + (circleShape.getRadius() - text.getGlobalBounds().height) / 2.f - text.getLocalBounds().top
        );
    } else {
        text.setPosition(
            shape.getPosition().x + (shape.getSize().x - text.getGlobalBounds().width) / 2.f,
            shape.getPosition().y + (shape.getSize().y - text.getGlobalBounds().height) / 2.f - text.getLocalBounds().top
        );
    }
}
