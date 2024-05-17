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
    Ghost( float radius = 10.0f, float speed = 100.0f);
    void move(sf::Time deltaTime, GameBoard& board);
    void chase(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
    void chase_1(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
    void chase2(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);

   // void moveRandom();
    //void draw(sf::RenderWindow & window) const;
   //void displayPosition() const;
};
#endif //PROJECT1_GHOST_H
