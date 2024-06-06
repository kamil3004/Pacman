#ifndef PROJECT1_GHOST_H
#define PROJECT1_GHOST_H
#include "Characters.h"
#include "GameBoard.h"
#include <SFML/Graphics.hpp>


/**
 * @brief Klasa Ghost dziedziczy po klasie Characters i reprezentuje ducha w grze Pac-Man.
 */
class Ghost :public Characters {
public:

    /**
     * @brief Konstruktor klasy Ghost.
     *
     * @param radius Promień ducha.
     * @param color Kolor ducha.
     * @param speed Prędkość ducha.
     *
     * Inicjalizuje ducha z podanymi parametrami.
     */
    Ghost(float radius, const sf::Color& color, float speed);

    /**
   * @brief Metoda chase umożliwia duchowi ściganie Pac-Mana.
   *
   * @param pacmanPosition Pozycja Pac-Mana.
   * @param deltaTime Czas, jaki upłynął od ostatniej aktualizacji.
   * @param board Plansza gry, używana do sprawdzania kolizji.
   *
   * Aktualizuje pozycję ducha, aby ścigał Pac-Mana, uwzględniając kolizje z planszą.
   */
    void chase( sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board);
};
#endif //PROJECT1_GHOST_H
