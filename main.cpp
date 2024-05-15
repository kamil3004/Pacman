#include <iostream>
#include <SFML/Graphics.hpp>
#include <array>
#include "files/PacMan.h"
#include "files/GameBoard.h"
#include "files/Ghost.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pacman Game");

    PacMan pacman;
    pacman.setSpeed(200.0f);
    pacman.setPosition(400.0f, 300.0f);

    Ghost ghost;
    ghost.setPosition(100.0f, 100.0f);

    GameBoard board;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        pacman.move(deltaTime, board);
        ghost.chase(pacman.getPosition(), deltaTime, board);

        window.clear();
        board.draw(window);
        pacman.draw(window);
        ghost.draw(window);
        window.display();
    }
    return 0;
}
/*
int main() {
    GameBoard board;

    srand(time(NULL));
    std::cout << "Hello, World!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Pac-Man");
    sf::Clock clock;
    sf::Time deltaTime;

    PacMan pacman;
    Ghost ghost;

    pacman.setPosition(400.0f, 300.0f);
    ghost.setPosition(100.0f, 100.0f);

    while (window.isOpen()) {
       // sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

       // pacman.move(deltaTime);
        //ghost.chase(pacman.getPosition(), deltaTime);

        window.clear();
        board.draw(window);
        //pacman.draw(window);
        //ghost.draw(window);

        window.display();
    }


    return 0;
}
*/