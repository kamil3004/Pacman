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
    int x = position.x;
    int y = position.y;
    std::cout << x << " " << y << std::endl;
}