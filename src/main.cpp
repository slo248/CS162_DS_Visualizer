#include "SLL.h"
#include "Figure.h"
#include "CodeBox.h"

namespace WindowConfig
{
    const int WIDTH = 1500;
    const int HEIGHT = 800;
    const int FPS = 60;
    const sf::String TITLE = "Data Structure Visualizer";
    const sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
    const sf::ContextSettings SETTINGS = sf::ContextSettings(0, 0, 16);
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

    // load sanfrancisco font
    sf::Font sanf;
    if(!sanf.loadFromFile("media/font/SFProDisplay.ttf")){
        std::cout << "Error: sanfrancisco font not found" << std::endl;
        return 1;
    }
    //

    // load consolas font
    sf::Font consolas;
    if(!consolas.loadFromFile("media/font/consola.ttf")){
        std::cout << "Error: consolas font not found" << std::endl;
        return 1;
    }
    //

    // load background image
    sf::Texture bgTexture;
    if(!bgTexture.loadFromFile("media/image/bg.jpg")){
        std::cout << "Error: background image not found" << std::endl;
        return 1;
    }
    sf::Sprite bgSprite;
    bgSprite.setTexture(bgTexture);
    bgSprite.setScale(
        (float)WindowConfig::WIDTH/(float)bgTexture.getSize().x,
        (float)WindowConfig::HEIGHT/(float)bgTexture.getSize().y
    );
    //

    // gen SLL
    SLL sll(&window, &sanf, &consolas, &bgSprite, WindowConfig::FPS, figure.circle, figure.arrow);
    sll.run();
    return 0;
}