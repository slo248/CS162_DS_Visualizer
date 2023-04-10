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
    {
        sf::FloatRect bounds = hCircle.getLocalBounds();
        hCircle.setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
    //
    // Solid circle
    //
    sf::CircleShape sCircle;
    sCircle.setRadius(30);
    {
        sf::FloatRect bounds = sCircle.getLocalBounds();
        sCircle.setOrigin(
            bounds.left + bounds.width / 2.f,
            bounds.top + bounds.height / 2.f
        );
    }
    //

    Node node(1, sf::Vector2f(100, 100));

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear(sf::Color::White);
        node.draw(&window, &hCircle, sf::Color::Red, sf::Color::Black, 0);
        window.display();
    }

    return 0;
}