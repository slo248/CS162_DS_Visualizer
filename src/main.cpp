#include "Graph.h"

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
    window.setFramerateLimit(60);
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
    
    Graph graph(&window, &hCircle, &sCircle);
    graph.addStep(60);
    graph.drawGrow(&node, Hollow, Colors::GREEN, Colors::BLACK);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event))
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }

        window.clear(sf::Color::White);
        graph.draw();
        window.display();
    }

    return 0;
}