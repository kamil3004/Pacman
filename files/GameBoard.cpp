//
// Created by admin on 24.04.2024.
//

#include "GameBoard.h"
#include "PacMan.h"
#include "characters.h"
#include "Ghost.h"
#include <iostream>

GameBoard::GameBoard() {
    // Inicjalizacja tekstury ściany
    wallTexture.loadFromFile("../files/wall.png");
        // Obsługa błędu, jeśli nie udało się załadować tekstury
        // Można też użyć domyślnej koloru ściany lub innego pliku graficznego
        // np. wallTexture.loadFromFile("default_wall_texture.png");
        // lub wallSprite.setFillColor(sf::Color::Blue);

    wallSprite.setTexture(wallTexture);

    // Ustawienie kształtów labiryntu
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == 0 || i == 19 || j == 0 || j == 19) {
                // Jeśli to krawędź planszy, ustaw ścianę
                maze[i][j].setSize(sf::Vector2f(20, 20)); // Rozmiar pojedynczego pola na planszy
                maze[i][j].setFillColor(sf::Color::Blue); // Kolor ściany
                maze[i][j].setPosition(i * 40, j * 40); // Pozycja na planszy
            }
        }
    }
}

void GameBoard::draw(sf::RenderWindow& window) const {
    // Rysowanie labiryntu
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if (i == 0 || i == 19 || j == 0 || j == 19) {
                // Rysuj ścianę
                window.draw(maze[i][j]);
            }
        }
    }
}
