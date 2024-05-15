//
// Created by admin on 24.04.2024.
//

#include "GameBoard.h"
#include <iostream>

GameBoard::GameBoard() : tileSize(40.0f, 40.0f) {
    loadBoard();
}

void GameBoard::loadBoard() {
    std::vector<std::string> level = {
            " ################### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #.................# ",
            " #.##.#.#####.#.##.# ",
            " #....#...#...#....# ",
            " ####.### # ###.#### ",
            "    #.#       #.#    ",
            "#####.# ##=## #.#####",
            "     .  #####  .     ",
            "#####.# ##### #.#####",
            "    #.#       #.#    ",
            " ####.# ##### #.#### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #..#.....P.....#..# ",
            " ##.#.#.#####.#.#.## ",
            " #....#...#...#....# ",
            " #.######.#.######.# ",
            " #.................# ",
            " ################### "
    };

    for (int y = 0; y < level.size(); ++y) {
        for (int x = 0; x < level[y].size(); ++x) {
            if (level[y][x] == '#') {
                sf::RectangleShape wall(tileSize);
                wall.setPosition(x * tileSize.x, y * tileSize.y);
                wall.setFillColor(sf::Color::Blue);
                walls.push_back(wall);
            }
        }
    }
}

void GameBoard::draw(sf::RenderWindow& window) {
    for (const auto& wall : walls) {
        window.draw(wall);
    }
}

bool GameBoard::checkCollision(const sf::CircleShape& shape) {
    for (const auto& wall : walls) {
        if (shape.getGlobalBounds().intersects(wall.getGlobalBounds())) {
            return true;
        }
    }
    return false;
}