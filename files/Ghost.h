//
// Created by admin on 05.05.2024.
//

#ifndef PROJECT1_GHOST_H
#define PROJECT1_GHOST_H
#include "characters.h"
#include <SFML/Graphics.hpp>

class Ghost :public characters {
private:
    sf::CircleShape shape;
    float speed;
public:
    Ghost(float radius = 10.f, float speed = 5.f);
    void moveRandom();
    void draw(sf::RenderWindow &window) const;
    sf::Vector2f getPosition() const;
};

#endif //PROJECT1_GHOST_H
