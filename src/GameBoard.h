#ifndef PROJECT1_GAMEBOARD_H
#define PROJECT1_GAMEBOARD_H
#include <SFML/Graphics.hpp>
#include <vector>


class GameBoard {
private:
    std::vector<sf::RectangleShape> walls;
    sf::Vector2f tileSize;
    std::vector<sf::CircleShape> dots;
public:
    GameBoard();
    void draw(sf::RenderWindow& window);
    void loadBoard();
    bool checkCollision(const sf::Vector2f& position, float radius);
    int checkDotCollision(sf::CircleShape& pacmanShape);
};
#endif //PROJECT1_GAMEBOARD_H
