#include <iostream>
#include <SFML/Graphics.hpp>
#include "files/PacMan.h"
#include "files/GameBoard.h"
#include "files/Ghost.h"

#include "files/Game_contrl.h"
int main()
{

    Game_contrl game;
    game.run();



//    GameBoard board;
//    PacMan pacman;
//    Ghost ghost;
//    Ghost ghost1;
//
//
//    sf::RenderWindow window(sf::VideoMode(840, 880), "Pacman Game", sf::Style::Resize | sf::Style::Close);
//
//
//    pacman.setSpeed(200.0f);
//    pacman.setPosition(420.0f, 620.0f);
//
//    ghost.setPosition(90.0f, 90.0f);
//    ghost1.setPosition(620.0f,360.0f);
//
//
//
//    sf::Font font;
//    if (!font.loadFromFile("..//files/arial.ttf")) {
//        return -1;
//    }
//    sf::Text scoreText;
//    scoreText.setFont(font);
//    scoreText.setCharacterSize(24);
//    scoreText.setFillColor(sf::Color::White);
//    scoreText.setPosition(10, 840);
//
//    sf::Clock clock;
//
//    while (window.isOpen()) {
//        sf::Time deltaTime = clock.restart();
//
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//        }
//        if(pacman.getPosition()==ghost.getPosition()|| pacman.getPosition()==ghost1.getPosition()){
//
//            std::cout << "You lose ";
//            window.close();
//        }
//        pacman.move(deltaTime, board);
//        ghost1.chase1(pacman.getPosition(),deltaTime,board);
//        ghost.chase1(pacman.getPosition(), deltaTime, board);
//        pacman.getPosition();
//        ghost.getPosition();
//
//        if (pacman.getPosition()==ghost.getPosition())
//        {
//            std::cout<<"You lose" ;
//            window.close();
//
//        }
//        if (pacman.getScore()==150)
//        {
//            std::cout<<"You win!! " ;
//            window.close();
//
//        }
//
//
//        window.clear();
//        board.draw(window);
//        pacman.draw(window);
//        ghost.draw(window);
//        ghost1.draw(window);
//        //Wyświetlanie punktów
//        scoreText.setString("Score: " + std::to_string(pacman.getScore()));
//        window.draw(scoreText);
//
//
//        window.display();
//
//    }
    return 0;
}
