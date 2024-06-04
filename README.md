
# Gra Pac-Man z SFML

To jest prosta gra Pac-Man zaimplementowana w C++ z użyciem biblioteki SFML (Simple and Fast Multimedia Library). Gra zawiera podstawowe mechaniki rozgrywki, w tym poruszanie się Pac-Mana po planszy, zbieranie kropek i unikanie duchów. Duchy ścigają Pac-Mana za pomocą prostego algorytmu.





## Wymagania 


Kompilator C++ (GCC, Clang, MSVC, itp.)

Biblioteka SFML (wersja 2.5.1 lub nowsza)




## Użycie

Sterowanie

Klawisze strzałek: Poruszanie Pac-Manem w odpowiednich kierunkach

Enter: Rozpoczęcie gry z ekranu startowego

Escape: Wyjście z gry


Rozgrywka

Cel: Poruszaj Pac-Manem po planszy, aby zebrać wszystkie kropki, unikając duchów.

Wygrana: Zbierz wszystkie kropki, aby wygrać grę.

Przegrana: Jeśli duch złapie Pac-Mana, przegrywasz grę.
    
## Klasy i funkcjonalność

### GameControl
Zarządza główną pętlą gry, inicjalizuje i aktualizuje wszystkie elementy gry.

###  Board
Ładuje planszę gry, zarządza ścianami i kropkami oraz obsługuje wykrywanie kolizji.

###  Pacman
Obsługuje ruch Pac-Mana, pozycję, wynik i rysowanie na ekranie.

### Ghost
Obsługuje ruch duchów, pozycję, algorytm ścigania AI oraz rysowanie na ekranie.

### GhostManager
Zarządza wieloma duchami, aktualizuje ich pozycje i obsługuje rysowanie.

### Funkcje:
#### Płynny ruch Pac-Mana i duchów.
#### Podstawowe algorytmu dla duchów, aby ścigały Pac-Mana.
#### Tunelowe przejścia dla Pac-Mana, umożliwiające przechodzenie z jednej strony planszy na drugą.
#### Śledzenie i wyświetlanie wyniku.
#### Ekrany startowy i końcowy gry.

