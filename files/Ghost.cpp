//
// Created by admin on 05.05.2024.
//

#include "Ghost.h"
#include <cstdlib>
#include <ctime>

Ghost::Ghost(float radius, float speed) : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(radius, radius);
    srand(time(NULL));
    shape.setPosition(10,10);
    position.x=10;
    position.y=20;
}

void Ghost::moveRandom() {
    // Wybierz losowy kierunek ruchu - góra (1) lub dół (-1)
    int dirY = (rand() % 2 == 0) ? 1 : -1; // 1 lub -1
    int dirx = (rand() % 2 == 0) ? 1 : -1;

    // Przesuń ducha o losową wartość w wybranym kierunku
    shape.move(dirx, dirY * speed);
}

void Ghost::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

sf::Vector2f Ghost::getPosition() const {
    return shape.getPosition();
}

