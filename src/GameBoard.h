#ifndef PROJECT1_GAMEBOARD_H
#define PROJECT1_GAMEBOARD_H
#include <SFML/Graphics.hpp>
#include <vector>


class GameBoard {
private:
    std::vector<sf::RectangleShape> walls; ///< Kontener przechowujący kształty ścian.
    sf::Vector2f tileSize; ///< Rozmiar pojedynczej płytki na planszy.
    std::vector<sf::CircleShape> dots; ///< Kontener przechowujący kształty kropek.
public:

    /**
    * @brief Rysuje planszę gry na oknie.
    *
    * @param window Obiekt okna renderowania SFML.
    */
    GameBoard();

    /**
    * @brief Rysuje planszę gry na oknie.
    *
    * @param window Obiekt okna renderowania SFML.
    */
    void draw(sf::RenderWindow& window);

    /**
   * @brief Ładuje planszę gry, tworząc ściany i kropki.
   *
   * Inicjalizuje układ planszy gry na podstawie predefiniowanego wzorca.
   */
    void loadBoard();

    /**
     * @brief Sprawdza kolizję postaci ze ścianami.
     *
     * @param position Pozycja postaci.
     * @param radius Promień postaci.
     * @return bool Zwraca true, jeśli nastąpiła kolizja; w przeciwnym razie false.
     */
    bool checkCollision(const sf::Vector2f& position, float radius);

    /**
     * @brief Sprawdza kolizję Pac-Mana z kropkami.
     *
     * @param pacmanShape Kształt Pac-Mana.
     * @return int Zwraca liczbę zjedzonych kropek.
     */
    int checkDotCollision(sf::CircleShape& pacmanShape);
};
#endif //PROJECT1_GAMEBOARD_H
