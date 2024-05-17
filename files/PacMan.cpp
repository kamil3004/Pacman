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

//void PacMan::setSpeed(float newSpeed) {
//    speed = newSpeed;
//}

void PacMan::move(sf::Time deltaTime, GameBoard& board) {
    float moveDistance = speed * deltaTime.asSeconds();
    sf::Vector2f movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= moveDistance;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += moveDistance;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= moveDistance;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += moveDistance;
    }

    sf::Vector2f newPosition = shape.getPosition() + movement;
    sf::Vector2f currentPosition = shape.getPosition();
    shape.setPosition(newPosition);

    if (board.checkCollision(shape)) {
        shape.setPosition(currentPosition);
    } else {
        if (board.checkDotCollision(shape)) {
            eatDot();
        }
    }
}
//void PacMan::draw(sf::RenderWindow& window)  {
//    window.draw(shape);
//}
float PacMan::getSpeed() const {
    return speed;
}

//float PacMan::getRadius() const {
//    return shape.getRadius();
//}
void PacMan::displayPosition() const {
    sf::Vector2f pacmanPosition = getPosition();
    std::cout << "Pacman position: (" << pacmanPosition.x << ", " << pacmanPosition.y << ")" << std::endl;
}
void PacMan::eatDot() {
    score += 10;
}
int PacMan::getScore() const {
    return score;
}
void PacMan::resetScore() {
    score = 0;
}