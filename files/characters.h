//
// Created by admin on 24.04.2024.
//

#ifndef PROJECT1_CHARACTERS_H
#define PROJECT1_CHARACTERS_H
#include <SFML/Graphics.hpp>

class characters {
public:
    sf::CircleShape shape;
    void setPosition(float x, float y);
private:
    float radius=10.0f/2;
protected:
    sf::Vector2f position;
};


#endif //PROJECT1_CHARACTERS_H
