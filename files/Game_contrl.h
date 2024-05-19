//
// Created by admin on 17.05.2024.
//

#ifndef PACMAN_GAME_CONTRL_H
#define PACMAN_GAME_CONTRL_H
#include <SFML/Graphics.hpp>
#include "PacMan.h"
#include "GameBoard.h"
#include "Ghost.h"

class Game_contrl {
public:
    Game_contrl();
    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void resetGame();
    enum GameState { Playing, GameOver, GameWon, StartScreen } gameState;

    sf::RenderWindow window;
    PacMan pacman;
    Ghost ghost1;
    Ghost ghost;
    Ghost ghost2;
    GameBoard board;
    sf::Font font;
    sf::Text scoreText;
    sf::Text messageText;
    sf::Clock clock;
};


#endif //PACMAN_GAME_CONTRL_H
