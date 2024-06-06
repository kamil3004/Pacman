#ifndef PROJECT1_CHARACTERS_H
#define PROJECT1_CHARACTERS_H
#include <SFML/Graphics.hpp>
/**
 * @brief Klasa Characters reprezentuje wspólne cechy dla postaci w grze, takich jak Pac-Man i duchy.
 */
class Characters {
public:
    /**
     * @brief Konstruktor klasy Characters.
     *
     * @param radius Promień postaci.
     * @param color Kolor postaci.
     * @param speed Początkowa prędkość postaci.
     */
    Characters(float radius, const sf::Color& color, float speed);


    sf::CircleShape shape; ///< Kształt postaci.
    /**
     * @brief Ustawia pozycję postaci.
     *
     * @param x Współrzędna X nowej pozycji.
     * @param y Współrzędna Y nowej pozycji.
     */
    void setPosition(float x, float y);

    /**
     * @brief Zwraca promień postaci.
     *
     * @return float Promień postaci.
     */
    float getRadius() const;

    /**
     * @brief Rysuje postać na oknie.
     *
     * @param window Obiekt sf::RenderWindow, na którym postać ma być narysowana.
     */
    void draw(sf::RenderWindow& window);

    /**
    * @brief Zwraca aktualną pozycję postaci.
    *
    * @return sf::Vector2f Wektor 2D zawierający współrzędne postaci.
    */
    sf::Vector2f getPosition() const;

    /**
    * @brief Ustawia nową prędkość postaci.
    *
    * @param newSpeed Nowa prędkość postaci.
    */
    void setSpeed(float newSpeed);

    /**
    * @brief Zwraca aktualną prędkość postaci.
    *
    * @return float Aktualna prędkość postaci.
    */
    float getSpeed() const;
protected:
    float speed; ///< Prędkość postaci.
};


#endif //PROJECT1_CHARACTERS_H

