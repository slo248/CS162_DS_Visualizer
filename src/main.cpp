#include "SLL.h"
#include "Figure.h"

namespace WindowConfig
{
    const int WIDTH = 1400;
    const int HEIGHT = 800;
    const int FPS = 60;
    const sf::String TITLE = "Data Structure Visualizer";
    const sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
    const sf::ContextSettings SETTINGS = sf::ContextSettings(0, 0, 8);
}

int main()
{
    system("cls");

    // gen window
    sf::RenderWindow window(
        sf::VideoMode(WindowConfig::WIDTH, WindowConfig::HEIGHT),
        WindowConfig::TITLE,
        WindowConfig::STYLE,
        WindowConfig::SETTINGS
    );
    window.setFramerateLimit(WindowConfig::FPS);
    //

    // gen figure
    Figure figure;
    //

    // font
    sf::Font sanf;
    if(!sanf.loadFromFile("media/font/SFProDisplay.ttf")){
        std::cout << "Error: font not found" << std::endl;
        return 1;
    }
    //

    // gen SLL
    SLL sll(&window, &sanf, WindowConfig::FPS, figure.hCircle, figure.sCircle, figure.arrow);
    sll.run();
    return 0;
}