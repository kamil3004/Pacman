//
// Created by admin on 05.05.2024.
//

#include "Ghost.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <SFML/System/Vector2.hpp>


Ghost::Ghost(float radius, float speed, sf::Color color) : speed(speed) {
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);
  }
void Ghost::chase2(sf::Vector2f& pacmanPosition, sf::Time deltaTime,  GameBoard& board){
    sf::Vector2f direction = pacmanPosition - shape.getPosition();

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
    // Oblicz nową pozycję ducha na podstawie kierunku i prędkości
    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime.asSeconds();

    // Sprawdź, czy nowa pozycja jest dozwolona na planszy
    if (!board.checkCollision(newPosition, getRadius())) {
        shape.setPosition(newPosition);
    } else {
        // Jeśli napotkano przeszkodę, zmień kierunek ruchu w sposób losowy

        int randomAngle = std::rand() % 360; // Losowy kąt od 0 do 359 stopni
        float randomDirectionX = std::cos(randomAngle * 3.14159 / 180); // Przeliczenie na radiany
        float randomDirectionY = std::sin(randomAngle * 3.14159 / 180);
        sf::Vector2f randomDirection(randomDirectionX, randomDirectionY);
        newPosition = shape.getPosition() + randomDirection * speed * deltaTime.asSeconds();

        // Sprawdź, czy nowa pozycja pozwala na uniknięcie przeszkody
        if (!board.checkCollision(newPosition, getRadius())) {
            shape.setPosition(newPosition);
        }
    }
}
//void Ghost::move(sf::Time deltaTime, GameBoard& board) {
//    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime.asSeconds();
//
//    // Backup current position
//    sf::Vector2f currentPosition = shape.getPosition();
//
//    shape.setPosition(newPosition);
//
//    // Sprawdź kolizję z przeszkodami
//    if (board.checkCollision(shape)) {
//        // Revert to previous position if collision detected
//        shape.setPosition(currentPosition);
//    }
//}
//
//
//
//void Ghost::chase(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board) {
//    sf::Vector2f direction = pacmanPosition - shape.getPosition();
//
//    // Normalizacja wektora kierunku
//    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//    direction /= length;
//
//    // Oblicz nową pozycję ducha na podstawie kierunku i prędkości
//    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime.asSeconds();
//
//    // Sprawdź, czy nowa pozycja jest dozwolona na planszy
//    if (!board.checkCollision(shape)) {
//        shape.setPosition(newPosition);
//    } else {
//        // Jeśli napotkano przeszkodę, zmień kierunek ruchu w sposób losowy
//        int randomAngle = std::rand() % 360; // Losowy kąt od 0 do 359 stopni
//        float randomDirectionX = std::cos(randomAngle * 3.14159 / 180); // Przeliczenie na radiany
//        float randomDirectionY = std::sin(randomAngle * 3.14159 / 180);
//        sf::Vector2f randomDirection(randomDirectionX, randomDirectionY);
//        newPosition = shape.getPosition() + randomDirection * speed * deltaTime.asSeconds();
//
//        // Sprawdź, czy nowa pozycja pozwala na uniknięcie przeszkody
//        if (!board.checkCollision(shape)) {
//            shape.setPosition(newPosition);
//        }
//    }
//}
//void Ghost::chase_1(const sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board) {
//    float moveDistance = speed * deltaTime.asSeconds();
//    sf::Vector2f ghostPosition = shape.getPosition();
//    sf::Vector2f direction = pacmanPosition - ghostPosition;
//    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
//
//    // Jeśli duch jest blisko Pacmana, wprowadź losowy ruch
//    if (distance < 40.0f) { // odległość w pikselach
//        int randomDirection = std::rand() % 4;
//        switch (randomDirection) {
//            case 0: direction = sf::Vector2f(1, 0); break; // prawo
//            case 1: direction = sf::Vector2f(-1, 0); break; // lewo
//            case 2: direction = sf::Vector2f(0, 1); break; // dół
//            case 3: direction = sf::Vector2f(0, -1); break; // góra
//        }
//    } else {
//        if (distance != 0) {
//            direction /= distance; // Normalizacja wektora kierunku
//        }
//    }
//
//    sf::Vector2f newPosition = ghostPosition + direction * moveDistance;
//
//    // Backup current position
//    sf::Vector2f currentPosition = shape.getPosition();
//
//    shape.setPosition(newPosition);
//
//    // Sprawdź kolizję z przeszkodami
//    if (board.checkCollision(shape)) {
//        // Revert to previous position if collision detected
//        shape.setPosition(currentPosition);
//    }
//}
