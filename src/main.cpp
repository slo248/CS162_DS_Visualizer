#include <SFML/Graphics.hpp>

int main()
{
    system("cls");
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "SFML works!",
        sf::Style::Titlebar | sf::Style::Close,
        settings
    );

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