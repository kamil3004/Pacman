#include "Ghost.h"
#include <cstdlib>
#include <cmath>
#include <SFML/System/Vector2.hpp>


Ghost::Ghost(float radius, const sf::Color& color, float speed) : Characters(radius, color, speed) {

  }
void Ghost::chase(sf::Vector2f& pacmanPosition, sf::Time deltaTime, GameBoard& board){
    sf::Vector2f direction = pacmanPosition - shape.getPosition();

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;

    //Oblicz nową pozycję ducha na podstawie kierunku i prędkości

    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime.asSeconds();

    //Sprawdź, czy nowa pozycja jest dozwolona na planszy

    if (!board.checkCollision(newPosition, getRadius())) {
        shape.setPosition(newPosition);
    } else {

        //Jeśli napotkano przeszkodę, zmień kierunek ruchu w sposób losowy
        int randomAngle = std::rand() % 360; // Losowy kąt od 0 do 359 stopni
         float randomDirectionX = std::cos(randomAngle * 3.14159 / 180); // Przeliczenie na radiany
         float randomDirectionY = std::sin(randomAngle * 3.14159 / 180);
         sf::Vector2f randomDirection(randomDirectionX, randomDirectionY);
         newPosition = shape.getPosition() + randomDirection * speed * deltaTime.asSeconds();

         //  Sprawdź, czy nowa pozycja pozwala na uniknięcie przeszkody

        if (!board.checkCollision(newPosition, getRadius())) {
            shape.setPosition(newPosition);
        }
    }
}

