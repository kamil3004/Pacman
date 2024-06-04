#ifndef PROJECT1_PACMAN_H
#define PROJECT1_PACMAN_H
#include "Characters.h"
#include "GameBoard.h"


class PacMan : public Characters {
private:
    int score;
public:
    PacMan(float radius, const sf::Color& color, float speed);
    void move(sf::Time deltaTime, GameBoard& board, const sf::RenderWindow& window);
    int getScore() const;
    void eatDot();
    void resetScore();
};


#endif //PROJECT1_PACMAN_H
