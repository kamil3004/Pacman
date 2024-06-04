#include "GameBoard.h"
#include <vector>


GameBoard::GameBoard() : tileSize(40.0f, 40.0f) {
    loadBoard();
}

void GameBoard::loadBoard() {
    const std::vector<std::string> level = {
            " ################### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #.................# ",
            " #.##.#.#####.#.##.# ",
            " #....#...#...#....# ",
            " ####.###.#.###.#### ",
            "    #.#.......#.#    ",
            "#####.#.##.##.#.#####",
            "    ....#####....     ",
            "#####.#.#####.#.#####",
            "    #.#.......#.#    ",
            " ####.#.#####.#.#### ",
            " #........#........# ",
            " #.##.###.#.###.##.# ",
            " #..#...........#..# ",
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
            } else if (level[y][x] == '.') {
                sf::CircleShape dot(5.0f);
                dot.setFillColor(sf::Color::White);
                dot.setOrigin(dot.getRadius(), dot.getRadius());
                dot.setPosition(x * tileSize.x + tileSize.x / 2, y * tileSize.y + tileSize.y / 2);
                dots.push_back(dot);


            }
        }
    }
}

void GameBoard::draw(sf::RenderWindow& window) {
    for (const auto& wall : walls) {
        window.draw(wall);
    }
    for (const auto& dot : dots) {
        window.draw(dot);
    }
}

bool GameBoard::checkCollision(const sf::Vector2f& position, float radius) {
    for (const auto& wall : walls) {
        if (wall.getGlobalBounds().intersects(sf::FloatRect(position.x - radius, position.y - radius, 2 * radius, 2 * radius))) {
            return true;
        }
    }
    return false;
}
int GameBoard::checkDotCollision(sf::CircleShape& pacmanShape) {
    int points = 0;
    for (auto it = dots.begin(); it != dots.end();) {
        if (pacmanShape.getGlobalBounds().intersects(it->getGlobalBounds())) {
            it = dots.erase(it);
            points++;
        } else {
            ++it;
        }
    }
    return points;
}
