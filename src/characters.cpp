//
// Created by admin on 24.04.2024.
//

#include "characters.h"

characters::characters(float radius, const sf::Color& color, float speed): speed(speed){
        shape.setRadius(radius);
        shape.setFillColor(color);
        shape.setOrigin(radius, radius);
}

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
float characters::getSpeed() const {
    return speed;
}
