#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
   sf::RenderWindow window(sf::VideoMode(400, 400), "lollll");
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent((event)))
        {
            if (event.type==sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }

    return 0;
}
