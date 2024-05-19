//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_CHARACTERS_H
#define PROJECT1_CHARACTERS_H
#include <SFML/Graphics.hpp>

class characters {
    float speed;
public:
    void setColor(const sf::Color& color);
    sf::CircleShape shape;
    void setPosition(float x, float y);
    float getRadius() const;
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    void setSpeed(float newSpeed);
protected:
    sf::Vector2f position;
};


#endif //PROJECT1_CHARACTERS_H
