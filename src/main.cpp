#include "Node.h"
#include <SFML/Graphics.hpp>

int main()
{
    system("cls");

    // window init
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "SFML works!",
        sf::Style::Titlebar | sf::Style::Close,
        settings
    );
    //

    // Circle init
    // Hollow circle
    sf::CircleShape hCircle;
    hCircle.setRadius(30);
    hCircle.setOutlineThickness(5);
    //
    // Solid circle
    //
    sf::CircleShape sCircle;
    sCircle.setRadius(30);
    //

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}