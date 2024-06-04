//
// Created by admin on 05.05.2024.
//

#ifndef PROJECT1_GHOST_H
#define PROJECT1_GHOST_H
#include "characters.h"
#include "GameBoard.h"
#include <SFML/Graphics.hpp>

class Ghost :public characters {
public:
    Ghost(float radius, const sf::Color& color, float speed);
    void chase( sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
};
#endif //PROJECT1_GHOST_H
