#ifndef PACMAN_GAMECONTROL_H
#define PACMAN_GAMECONTROL_H
#include <SFML/Graphics.hpp>
#include "PacMan.h"
#include "GameBoard.h"
#include "Ghost.h"
#include <vector>

/**
 * /**
 * @brief Klasa GameControl zarządza główną logiką gry, w tym inicjalizacją, obsługą zdarzeń, aktualizacjami i renderowaniem.
 */
class GameControl {
public:

    /**
     * @brief Konstruktor klasy GameControl.
     *
     * Inicjalizuje grę, tworzy okno i ładuje zasoby.
     */
    GameControl();

    /**
     * @brief Uruchamia główną pętlę gry.
     *
     * Obsługuje zdarzenia, aktualizuje stan gry i renderuje grafikę.
     */
    void run();
private:
    void processEvents();

    /**
     * @brief Aktualizuje stan gry.
     *
     * @param deltaTime Czas, jaki upłynął od ostatniej aktualizacji.
     *
     * Aktualizuje pozycje postaci i sprawdza kolizje.
     */
    void update(sf::Time deltaTime);

    /**
     * @brief Renderuje grafikę gry.
     *
     * Rysuje wszystkie elementy gry na oknie.
     */
    void render();

    /**
     * @brief Resetuje grę do stanu początkowego.
     *
     * Ustawia postaci i planszę do stanu początkowego, resetuje wynik.
     */
    void resetGame();

    /**
     * @brief Oblicza odległość między dwoma punktami.
     *
     * @param pos1 Pierwsza pozycja.
     * @param pos2 Druga pozycja.
     * @return float Odległość między dwoma punktami.
     */
    float calculateDistance(const sf::Vector2f& pos1, const sf::Vector2f& pos2);

    /**
     * @brief Sprawdza kolizję między Pac-Manem a duchem.
     *
     * @param pacman Obiekt Pac-Mana.
     * @param ghost Obiekt ducha.
     * @return bool Zwraca true, jeśli nastąpiła kolizja; w przeciwnym razie false.
     */
    bool isColliding(const PacMan& pacman, const Ghost& ghost);

    /**
    * @brief Wylicza różne stany gry.
    */
    enum gameState { Playing, GameOver, GameWon, StartScreen } gameState;
    float distance; ///< Odległość używana w obliczeniach kolizji.
    sf::RenderWindow window; ///< Okno renderowania SFML.
    PacMan pacman; ///< Obiekt Pac-Mana.
    std::vector<Ghost> ghosts; ///< Wektor duchów.
    GameBoard board; ///< Plansza gry.
    sf::Font font; ///< Czcionka używana do tekstu w grze.
    sf::Text scoreText; ///< Tekst wyświetlający wynik.
    sf::Text messageText; ///< Tekst wyświetlający komunikaty.
    sf::Clock clock; ///< Zegar używany do mierzenia czasu w grze.

};


#endif //PACMAN_GAMECONTROL_H
