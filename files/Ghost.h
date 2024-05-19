//
// Created by admin on 05.05.2024.
//

#ifndef PROJECT1_GHOST_H
#define PROJECT1_GHOST_H
#include "characters.h"
#include "GameBoard.h"
#include <SFML/Graphics.hpp>

class Ghost :public characters {
private:
    float speed;
    sf::Vector2f direction;

public:
    Ghost( float radius = 10.0f, float speed = 100.0f,sf::Color color = sf::Color::Red);
    void move(sf::Time deltaTime, GameBoard& board);
    void chase(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
    void chase_1(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
    void chase2( sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
};
#endif //PROJECT1_GHOST_H
