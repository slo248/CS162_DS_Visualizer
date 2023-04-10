#include "SLL.h"
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

    // gen SLL
    SLL sll(&window, 60, figure.hCircle, figure.sCircle);
    sll.run();
    return 0;
}