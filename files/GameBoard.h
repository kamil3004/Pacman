//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_GAMEBOARD_H
#define PROJECT1_GAMEBOARD_H
#include "PacMan.h"
#include <SFML/Graphics.hpp>

enum GameState{RUNNING, FINISHED_WIN, FINISHED_LOSS};
struct Field
{
    bool hasGhost;
    bool hasPacman;
    bool hasDot;
    bool hasBigDot;
};

class GameBoard {
private:
    sf::RectangleShape maze[20][20]; // rozmiar planszy
    sf::Texture wallTexture;
    sf::Sprite wallSprite;

public:
    GameBoard();

    void draw(sf::RenderWindow& window) const;
};
#endif //PROJECT1_GAMEBOARD_H
