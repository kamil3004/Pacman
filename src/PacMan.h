#ifndef PROJECT1_PACMAN_H
#define PROJECT1_PACMAN_H
#include "Characters.h"
#include "GameBoard.h"

/**
 * @brief Klasa PacMan dziedziczy po klasie Characters i reprezentuje postać Pac-Mana w grze.
 */
class PacMan : public Characters {
private:
    int score;  ///< Aktualny wynik Pac-Mana.
public:

    /**
     * @brief Konstruktor klasy PacMan.
     *
     * @param radius Promień Pac-Mana.
     * @param color Kolor Pac-Mana.
     * @param speed Prędkość Pac-Mana.
     *
     * Inicjalizuje Pac-Mana z podanymi parametrami.
     */
    PacMan(float radius, const sf::Color& color, float speed);

    /**
     * @brief Metoda move umożliwia poruszanie się Pac-Mana.
     *
     * @param deltaTime Czas, jaki upłynął od ostatniej aktualizacji.
     * @param board Plansza gry, używana do sprawdzania kolizji.
     * @param window Okno renderowania, używane do sprawdzania wyjść poza ekran.
     *
     * Aktualizuje pozycję Pac-Mana, uwzględniając kolizje z planszą i granice ekranu.
     */
    void move(sf::Time deltaTime, GameBoard& board, const sf::RenderWindow& window);

    /**
     * @brief Pobiera aktualny wynik Pac-Mana.
     *
     * @return Aktualny wynik Pac-Mana.
     */
    int getScore() const;

    /**
    * @brief Zwiększa wynik Pac-Mana po zjedzeniu kropki.
    *
    * Zwiększa aktualny wynik Pac-Mana o określoną wartość po zjedzeniu kropki.
    */
    void eatDot();

    /**
     * @brief Resetuje wynik Pac-Mana do zera.
     *
     * Ustawia aktualny wynik Pac-Mana na zero.
     */
    void resetScore();
};


#endif //PROJECT1_PACMAN_H
