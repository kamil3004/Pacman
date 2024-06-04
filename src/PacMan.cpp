#include <SFML/Graphics.hpp>
#include "PacMan.h"

PacMan::PacMan(float radius, const sf::Color& color, float speed): Characters(radius, color, speed), score(0) {

}

void PacMan::move(sf::Time deltaTime, GameBoard& board, const sf::RenderWindow& window) {
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

    if (board.checkCollision(newPosition, getRadius())) {
        shape.setPosition(currentPosition);
    } else {
        if (board.checkDotCollision(shape)) {
            eatDot();
        }
    }

    sf::Vector2f position = shape.getPosition();
    if (position.x < 0) {
        shape.setPosition(window.getSize().x, position.y);
    } else if (position.x > window.getSize().x) {
        shape.setPosition(0, position.y);
    }

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