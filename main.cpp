#include "src/GameControl.h"

/**
 * @brief Funkcja główna programu.
 *
 * Tworzy obiekt GameControl i uruchamia grę.
 *
 * @return Zwraca 0, aby wskazać pomyślne zakończenie programu.
 */
int main()
{
    // Tworzenie obiektu GameControl, który zarządza grą.
    GameControl game;

    // Uruchomienie gry.
    game.run();

    // Zwracanie 0 oznacza poprawne zakończenie programu.
    return 0;
}
