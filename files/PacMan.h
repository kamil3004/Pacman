//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_PACMAN_H
#define PROJECT1_PACMAN_H
#include "characters.h"
#include "GameBoard.h"


class PacMan : public characters {
    char direction;
    float speed;
    int score;
public:
    PacMan(float radius = 10.f, float speed=250.0f);
    void move(sf::Time deltaTime, GameBoard& board, const sf::RenderWindow& window);
    int getScore() const;
    void eatDot();
    void resetScore();
    float getSpeed() const;
    void displayPosition() const;

};


#endif //PROJECT1_PACMAN_H
