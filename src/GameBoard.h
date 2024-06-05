#ifndef PROJECT1_GAMEBOARD_H
#define PROJECT1_GAMEBOARD_H
#include <SFML/Graphics.hpp>
#include <vector>


class GameBoard {
private:
    /**
     * vektor dla ścian,
     */
    std::vector<sf::RectangleShape> walls;
    /**
     * vektor dla rozmiaru okienka
     */
    sf::Vector2f tileSize;
    /**
     *  vektor dla kropek
     */
    std::vector<sf::CircleShape> dots;
public:
    /**
     * konstruktor
     */
    GameBoard();
    /**
     * rusuje okno na podstwaie window
     * @param window
     */
    void draw(sf::RenderWindow& window);
    /**
     * ładuje mapę
     */
    void loadBoard();
    /**
     * sprawdza kolizje na podstawie pozycji i rozmiaru obieków
     * @param position
     * @param radius
     * @return
     */
    bool checkCollision(const sf::Vector2f& position, float radius);
    /**
     * sprawdza kolizje z kropkami na podstawie pozycji i rozmiaru obieków
     * @param pacmanShape
     * @return
     */
    int checkDotCollision(sf::CircleShape& pacmanShape);
};
#endif //PROJECT1_GAMEBOARD_H
