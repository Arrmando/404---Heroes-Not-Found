#ifndef LIFEBAR_HPP
#define LIFEBAR_HPP

#include <SFML/Graphics.hpp>

class lifeBar {
public:
    lifeBar(float x, float y, float width, float height, const sf::Color& fillColor, float maxLife, float currentLife);
    
    void draw(sf::RenderWindow& window);
    void setHealth(float health);  // Atualiza a vida

private:
    float maxLife;           
    float currentLife;       
    float lifeWidth;          

    bool isFlashing;          
    sf::RectangleShape lifeFill;   
    sf::RectangleShape lifeBack;   
};

#endif
