//
// Created by admin on 05.05.2024.
//

#include "Ghost.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

Ghost::Ghost(float radius, float speed) : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius, radius);
}

//void Ghost::setPosition(float x, float y) {
//    shape.setPosition(x, y);
//}

sf::Vector2f Ghost::getPosition() const {
    return shape.getPosition();
}
void Ghost::move(sf::Time deltaTime, GameBoard& board) {
    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime.asSeconds();
    sf::Vector2f currentPosition = shape.getPosition();

    shape.setPosition(newPosition);

    // Sprawdź kolizję z przeszkodami
    if (board.checkCollision(shape)) {
        // Revert to previous position if collision detected
        shape.setPosition(currentPosition);
    }
}

void Ghost::chase(sf::Vector2f pacmanPosition, sf::Time deltaTime, GameBoard& board) {
    sf::Vector2f ghostPosition = getPosition();
    sf::Vector2f difference = pacmanPosition - ghostPosition;
    float length = std::sqrt(difference.x * difference.x + difference.y * difference.y);

    if (length != 0) {
        direction = difference / length;
    }

    move(deltaTime, board);
}

void Ghost::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
void Ghost::chase1(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board) {
    float moveDistance = speed * deltaTime.asSeconds();
    sf::Vector2f ghostPosition = shape.getPosition();
    sf::Vector2f direction = pacmanPosition - ghostPosition;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance != 0) {
        direction /= distance;
    }

    sf::Vector2f newPosition = ghostPosition + direction * moveDistance;

    // Backup current position
    sf::Vector2f currentPosition = shape.getPosition();

    shape.setPosition(newPosition);

    // Sprawdź kolizję z przeszkodami
    if (board.checkCollision(shape)) {
        // Revert to previous position if collision detected
        shape.setPosition(currentPosition);
    }
}






/*
void Ghost::moveRandom() {
    // Wybierz losowy kierunek ruchu - góra (1) lub dół (-1)
    int dirY = (rand() % 2 == 0) ? 1 : -1; // 1 lub -1
    int dirx = (rand() % 2 == 0) ? 1 : -1;

    // Przesuń ducha o losową wartość w wybranym kierunku
    shape.move(dirx, dirY * speed);
}

void Ghost::displayPosition() const {
    sf::Vector2f ghostPosition = getPosition();
    std::cout << "ghost position: (" << ghostPosition.x << ", " << ghostPosition.y << ")" << std::endl;
}
*/