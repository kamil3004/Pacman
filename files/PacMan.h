//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_PACMAN_H
#define PROJECT1_PACMAN_H
#include "characters.h"
#include "GameBoard.h"


class PacMan : public characters {
    bool dead;
    char direction;
    float speed;
    sf::CircleShape shape;
    int score;
public:
    PacMan(float radius = 10.f, float speed=250.0f);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void setSpeed(float newSpeed);
    void move(sf::Time deltaTime, GameBoard& board);
    void draw(sf::RenderWindow& window);
    int getScore() const;
    float getRadius() const;
    void eatDot();
    void resetScore();


    float getSpeed() const;
    void displayPosition() const;

};


#endif //PROJECT1_PACMAN_H
