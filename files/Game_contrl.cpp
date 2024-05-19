//
// Created by admin on 17.05.2024.
//

#include "Game_contrl.h"
#include <iostream>
#include <cmath>


Game_contrl::Game_contrl() : window(sf::VideoMode(840, 880), "Pacman", sf::Style::Resize | sf::Style::Close),gameState(StartScreen) {

    pacman.setSpeed(200.0f);
    pacman.setPosition(400.0f, 300.0f);

    ghost.setSpeed(100.0f);
    ghost.setPosition(100.0f, 100.0f);
    ghost.setColor(sf::Color::White);

    ghost2.setSpeed(100.0f);
    ghost2.setPosition(100.0f, 780.0f);
    ghost2.setColor(sf::Color::Green);

    if (!font.loadFromFile("../files/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 840);

    messageText.setFont(font);
    messageText.setCharacterSize(32);
    messageText.setFillColor(sf::Color::White);
    messageText.setPosition(200, 250);
    messageText.setString("To start press Enter");
}

void Game_contrl::run() {
    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game_contrl::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter) {
                if (gameState == StartScreen) {
                    gameState = Playing;
                } else if (gameState != Playing) {
                    resetGame();
                }
            }
        }

        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
    }
}

void Game_contrl::update(sf::Time deltaTime) {
    if (gameState == Playing) {
        sf::Vector2f pacmanPos = pacman.getPosition();
        sf::Vector2f ghostPos = ghost.getPosition();
        sf::Vector2f ghost2Pos = ghost2.getPosition();

        pacman.move(deltaTime, board, window);
        ghost.chase2(pacmanPos, deltaTime, board);
        ghost2.chase2(pacmanPos, deltaTime, board);


        float distance = std::sqrt((pacmanPos.x - ghostPos.x) * (pacmanPos.x - ghostPos.x) +
                                   (pacmanPos.y - ghostPos.y) * (pacmanPos.y - ghostPos.y));
        float distance2 = std::sqrt((pacmanPos.x - ghost2Pos.x) * (pacmanPos.x - ghost2Pos.x) +
                                   (pacmanPos.y - ghost2Pos.y) * (pacmanPos.y - ghost2Pos.y));

        if (distance < (pacman.getRadius() + ghost.getRadius())) {
            gameState = GameOver;
            messageText.setString("You lose!\nPress Enter to restart.");
        }
        if (distance2 < (pacman.getRadius() + ghost2.getRadius())) {
            gameState = GameOver;
            messageText.setString("You lose!\nPress Enter to restart.");
        }

        if (pacman.getScore() == 1790) {
            gameState = GameWon;
            messageText.setString("You win!!\nPress Enter to restart.");
        }
    }
}

void Game_contrl::render() {
    if (gameState == StartScreen || gameState == GameOver || gameState == GameWon) {
        window.clear(sf::Color::Black);
    } else {
        window.clear();
        board.draw(window);
        pacman.draw(window);
        ghost.draw(window);
        ghost2.draw(window);
    }

    if (gameState == StartScreen || gameState == GameOver || gameState == GameWon) {
        window.draw(messageText);
    }
    else {
        scoreText.setString("Score: " + std::to_string(pacman.getScore()));
        window.draw(scoreText);
    }

    window.display();

}

void Game_contrl::resetGame() {
    pacman.setPosition(400.0f, 300.0f);
    ghost.setPosition(100.0f, 100.0f);
    ghost2.setPosition(100.0f, 780.0f);
    pacman.setSpeed(200.0f);
    ghost.setSpeed(100.0f);
    ghost2.setSpeed(100.0f);
    gameState = Playing;
    pacman.resetScore();
    board = GameBoard();
}