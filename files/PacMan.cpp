//
// Created by admin on 24.04.2024.
//
#include <SFML/Graphics.hpp>
#include "PacMan.h"
#include <iostream>

PacMan::PacMan(float radius, float speed) : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(radius, radius);
    shape.setPosition(10,10);
    //position.x=10;
    //position.y=10;
}

void PacMan::move(sf::Vector2f offset) {
    shape.move(offset);
}

void PacMan::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f PacMan::getPosition() const {
    return shape.getPosition();
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