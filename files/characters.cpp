//
// Created by admin on 24.04.2024.
//

#include "characters.h"

//przenieść tu set position
void characters::setPosition(float x, float y) {
    shape.setPosition(x, y);
}
float characters::getRadius() const {
    return shape.getRadius();
}
void characters::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
sf::Vector2f characters::getPosition() const{
    return shape.getPosition();
}
void characters::setSpeed(float newSpeed) {
    speed = newSpeed;
}
void characters::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}