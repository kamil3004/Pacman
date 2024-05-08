//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_PACMAN_H
#define PROJECT1_PACMAN_H
#include "characters.h"


class PacMan : public characters {
    bool dead;
    char direction;
    sf::CircleShape shape;
    float speed;

public:
    PacMan(float radius = 10.f, float speed = 5.f);
    void move(sf::Vector2f offset);
    void draw(sf::RenderWindow& window) const;
    sf::Vector2f getPosition() const;
    float getSpeed() const;
    float getRadius() const;
    void displayPosition() const;
};


#endif //PROJECT1_PACMAN_H
