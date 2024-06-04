#ifndef PACMAN_GAMECONTROL_H
#define PACMAN_GAMECONTROL_H
#include <SFML/Graphics.hpp>
#include "PacMan.h"
#include "GameBoard.h"
#include "Ghost.h"
#include <vector>

class GameControl {
public:
    GameControl();
    void run();
private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    void resetGame();
    float calculateDistance(const sf::Vector2f& pos1, const sf::Vector2f& pos2);
    bool isColliding(const PacMan& pacman, const Ghost& ghost);
    enum GameState { Playing, GameOver, GameWon, StartScreen } gameState;
    float distance;
    sf::RenderWindow window;
    PacMan pacman;
    std::vector<Ghost> ghosts;
    GameBoard board;
    sf::Font font;
    sf::Text scoreText;
    sf::Text messageText;
    sf::Clock clock;

};


#endif //PACMAN_GAMECONTROL_H
