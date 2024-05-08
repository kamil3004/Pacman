#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>

#include "files/PacMan.h"
#include "files/GameBoard.h"
#include "files/Ghost.h"



int main() {
    GameBoard board;

    srand(time(NULL));
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");

    PacMan pacman;
    Ghost ghost;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            //ghost.moveRandom();
            if (event.type == sf::Event::KeyPressed) {
                // Obsługa ruchu Pac-Mana za pomocą strzałek
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        pacman.move(sf::Vector2f(0.f, -40.f)); // Przesuń o jedno pole do góry (40 pikseli)
                        break;
                    case sf::Keyboard::Down:
                        pacman.move(sf::Vector2f(0.f, 40.f)); // Przesuń o jedno pole w dół (40 pikseli)
                        break;
                    case sf::Keyboard::Left:
                        pacman.move(sf::Vector2f(-40.f, 0.f)); // Przesuń o jedno pole w lewo (40 pikseli)
                        break;
                    case sf::Keyboard::Right:
                        pacman.move(sf::Vector2f(40.f, 0.f)); // Przesuń o jedno pole w prawo (40 pikseli)
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear();
        // Rysowanie elementów gry
        board.draw(window);
        pacman.draw(window);
        ghost.draw(window);
        //pacman.displayPosition();
        ghost.moveRandom();

        window.display();
    }


    return 0;
}
