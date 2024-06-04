#ifndef PROJECT1_GHOST_H
#define PROJECT1_GHOST_H
#include "Characters.h"
#include "GameBoard.h"
#include <SFML/Graphics.hpp>

class Ghost :public Characters {
public:
    Ghost(float radius, const sf::Color& color, float speed);
    void chase( sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
};
#endif //PROJECT1_GHOST_H
