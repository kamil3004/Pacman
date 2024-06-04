//
// Created by admin on 17.05.2024.
//

#include "Game_contrl.h"
#include <iostream>
#include <cmath>



Game_contrl::Game_contrl() : window(sf::VideoMode(840, 880), "Pacman", sf::Style::Resize | sf::Style::Close),gameState(StartScreen),
    pacman(10.f, sf::Color::Yellow, 200.f)
    {

    pacman.setSpeed(200.0f);
    pacman.setPosition(400.0f, 300.0f);

    ghosts.emplace_back(11.f, sf::Color::Red, 100.f);
    ghosts.emplace_back(11.f, sf::Color::Magenta, 150.f);
    ghosts.emplace_back(11.f, sf::Color::Green, 80.f);
    ghosts.emplace_back(11.f, sf::Color::White, 50.f);

    ghosts[0].setPosition(100.f, 60.f);
    ghosts[1].setPosition(100.f, 780.f);
    ghosts[2].setPosition(740.f, 780.f);
    ghosts[3].setPosition(740.f, 60.f);

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
    sf::Event event{};
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
float Game_contrl::calculateDistance(const sf::Vector2f& pos1, const sf::Vector2f& pos2) {
    return std::sqrt((pos1.x - pos2.x) * (pos1.x - pos2.x) + (pos1.y - pos2.y) * (pos1.y - pos2.y));
}

bool Game_contrl::isColliding(const PacMan& pacman, const Ghost& ghost) {
    distance = calculateDistance(pacman.getPosition(), ghost.getPosition());
    return distance < (pacman.getRadius() + ghost.getRadius());
}


void Game_contrl::update(sf::Time deltaTime) {
    if (gameState == Playing) {
        sf::Vector2f pacmanPos = pacman.getPosition();
        pacman.move(deltaTime, board, window);

        for (auto& ghost : ghosts) {
            ghost.chase(pacmanPos, deltaTime, board);
        }

        for (const auto& ghost : ghosts) {
            if (isColliding(pacman, ghost)) {
                gameState = GameOver;
                messageText.setString("You lose!\nPress Enter to restart.");
            }
        }

        if (pacman.getScore() == 1800) {
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
        for (auto& ghost : ghosts) {
            ghost.draw(window);
        }
        for (auto& ghost : ghosts) {
            ghost.draw(window);
        }

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
    ghosts[0].setPosition(100.f, 60.f);
    ghosts[1].setPosition(100.f, 780.f);
    ghosts[2].setPosition(740.f, 780.f);
    ghosts[3].setPosition(740.f, 60.f);
    gameState = Playing;
    pacman.resetScore();
    board = GameBoard();
}