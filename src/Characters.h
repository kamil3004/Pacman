#ifndef PROJECT1_CHARACTERS_H
#define PROJECT1_CHARACTERS_H
#include <SFML/Graphics.hpp>

class Characters {
public:
    Characters(float radius, const sf::Color& color, float speed);
    sf::CircleShape shape;
    void setPosition(float x, float y);
    float getRadius() const;
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    void setSpeed(float newSpeed);
    float getSpeed() const;
protected:
    float speed;
};


#endif //PROJECT1_CHARACTERS_H
