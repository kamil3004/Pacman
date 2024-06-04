//
// Created by admin on 24.04.2024.
//

#include "Characters.h"

Characters::Characters(float radius, const sf::Color& color, float speed): speed(speed){
        shape.setRadius(radius);
        shape.setFillColor(color);
        shape.setOrigin(radius, radius);
}

void Characters::setPosition(float x, float y) {
    shape.setPosition(x, y);
}
float Characters::getRadius() const {
    return shape.getRadius();
}
void Characters::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
sf::Vector2f Characters::getPosition() const{
    return shape.getPosition();
}
void Characters::setSpeed(float newSpeed) {
    speed = newSpeed;
}
float Characters::getSpeed() const {
    return speed;
}
