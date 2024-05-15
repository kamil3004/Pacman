//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_GAMEBOARD_H
#define PROJECT1_GAMEBOARD_H
#include <SFML/Graphics.hpp>
#include <vector>


enum GameState{RUNNING, FINISHED_WIN, FINISHED_LOSS};


class GameBoard {
private:
    std::vector<sf::RectangleShape> walls;
    sf::Vector2f tileSize;
    std::vector<sf::CircleShape> dots;
public:
    GameBoard();
    void draw(sf::RenderWindow& window);
    void loadBoard();
    bool checkCollision(const sf::CircleShape& shape);
    int checkDotCollision(sf::CircleShape& pacmanShape);
};
#endif //PROJECT1_GAMEBOARD_H
