#include <iostream>
#include <SFML/Graphics.hpp>
#include "files/PacMan.h"
#include "files/GameBoard.h"
#include "files/Ghost.h"

int main()
{
    GameBoard board;
    PacMan pacman(5,250.0f);
    Ghost ghost(5);
    Ghost ghost1(5);


    sf::RenderWindow window(sf::VideoMode(840/2, 880/2), "Pacman Game", sf::Style::Resize | sf::Style::Close);


    pacman.setSpeed(200.0f);
    pacman.setPosition(420.0f/2, 620.0f/2);

    ghost.setPosition(90.0f/2, 90.0f/2);
    ghost1.setPosition(620.0f/2,360.0f/2);



    sf::Font font;
    if (!font.loadFromFile("..//files/arial.ttf")) {
        return -1;
    }
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(24/2);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 840/2);
    sf::Text Text;
    Text.setFont(font);
    Text.setCharacterSize(24);
    Text.setFillColor(sf::Color::Red);
    Text.setPosition(30, 840/2);



    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        pacman.move(deltaTime, board);
        ghost1.chase1(pacman.getPosition(),deltaTime,board);
        ghost.chase1(pacman.getPosition(), deltaTime, board);
        ghost.move(deltaTime,board);
        pacman.getPosition();
        ghost.getPosition();


        window.clear();
        if (pacman.getPosition()==ghost.getPosition())
        {
            std::cout<<"You lose" ;
            scoreText.setString("You Lose!! Score: " + std::to_string(pacman.getScore()));
            window.draw(Text);
           // break;
            //window.close();

        }
        if (pacman.getScore()==150)
        {
            std::cout<<"You win!! " ;
            scoreText.setString("You win!! Score: " + std::to_string(pacman.getScore()));
            window.draw(Text);
           // break;
            //window.close();

        }
        board.draw(window);
        pacman.draw(window);
        ghost.draw(window);
        ghost1.draw(window);
        //Wyświetlanie punktów
        scoreText.setString("Score: " + std::to_string(pacman.getScore()));
        window.draw(scoreText);


        window.display();

    }
    return 0;
}
