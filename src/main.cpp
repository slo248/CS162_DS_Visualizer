#include "Graph.h"
#include "Figure.h"

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

    // gen figure
    Figure figure;
    //

    // list of integers
    List<Node> list;
    list.pushBack(1);
    //

    Graph graph(&window, figure.hCircle, figure.sCircle);
    graph.addStep(60);
    graph.draw(&list,Hollow,Colors::GREEN,Colors::BLACK);

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