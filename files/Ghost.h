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
    sf::CircleShape shape;
    float speed;
    sf::Vector2f direction;

public:
    Ghost(float radius = 15.0f, float speed = 150.0f);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    void move(sf::Time deltaTime, GameBoard& board);
    void chase(sf::Vector2f pacmanPosition, sf::Time deltaTime, GameBoard& board);
    void draw(sf::RenderWindow& window);


   // void moveRandom();
    //void draw(sf::RenderWindow & window) const;
   //void displayPosition() const;
};
#endif //PROJECT1_GHOST_H
