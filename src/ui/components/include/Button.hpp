#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text text;
    float fontSize;

public:
    Button(float x, float y, float width, float height, const sf::Color& color, const std::string& label, sf::Font& font, float FontSize);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Vector2i& mousePos);
    bool isHover(const sf::Vector2i& mousePos) const;
    void setText(const std::string& label); 
    void setColor(const sf::Color& color);
    void setColorHover(const sf::Color& hoverColor, const sf::Color& defaultColor, sf::RenderWindow& window); 
};

#endif
