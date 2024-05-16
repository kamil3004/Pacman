//
// Created by admin on 24.04.2024.
//
#include <SFML/Graphics.hpp>
#include "PacMan.h"
//#include "GameBoard.h"
#include <iostream>

//GameBoard Board;
PacMan::PacMan(float radius, float speed) : speed(speed), score(0) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(radius, radius);
   // shape.setPosition(400,300);


}
/*
void PacMan::setPosition(float x, float y) {
    shape.setPosition(x, y);
}
 */
sf::Vector2f PacMan::getPosition() const {
    return shape.getPosition();
}

void PacMan::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void PacMan::move(sf::Time deltaTime, GameBoard& board) {

    float moveDistance = speed * deltaTime.asSeconds();
    sf::Vector2f newPosition = shape.getPosition();

    // Backup current position
    sf::Vector2f currentPosition = shape.getPosition();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        newPosition.y -= moveDistance;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        newPosition.y += moveDistance;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        newPosition.x -= moveDistance;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        newPosition.x += moveDistance;
    }

    shape.setPosition(newPosition);

    // Sprawdź kolizję z przeszkodami
    if (board.checkCollision(shape)) {
        // Revert to previous position if collision detected
        shape.setPosition(currentPosition);
    }else {
        // Sprawdź kolizję z kropkami
        score += board.checkDotCollision(shape);
    }
}

void PacMan::draw(sf::RenderWindow& window)  {
    window.draw(shape);
}
float PacMan::getSpeed() const {
    return speed;
}

float PacMan::getRadius() const {
    return shape.getRadius();
}
void PacMan::displayPosition() const {
    sf::Vector2f pacmanPosition = getPosition();
    std::cout << "Pacman position: (" << pacmanPosition.x << ", " << pacmanPosition.y << ")" << std::endl;
}

int PacMan::getScore() const {
    return score;
}