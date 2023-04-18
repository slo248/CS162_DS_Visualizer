#include "App.h"
#include "Config.h"

using namespace Config::Window;

App::App():
    window(
        sf::VideoMode(WIDTH, HEIGHT),
        TITLE,
        STYLE,
        SETTINGS
    )
{
    window.setFramerateLimit(FPS);

    if (!cons.loadFromFile("media/font/consola.ttf"))
    {
        std::cout << "Error loading consola.ttf" << std::endl;
    }
    if (!sanf.loadFromFile("media/font/SFProDisplay.ttf"))
    {
        std::cout << "Error loading SFProDisplay.ttf" << std::endl;
    }
    if (!bgImage.loadFromFile("media/image/bg.jpg"))
    {
        std::cout << "Error loading bg.jpg" << std::endl;
    }
    bgSprite.setTexture(bgImage);
    bgSprite.setScale(
        (float)WIDTH/bgImage.getSize().x,
        (float)HEIGHT/bgImage.getSize().y
    );

    sll=new SLL(&window,&sanf,&cons,FPS,figure.circle,figure.arrow);
}

App::~App()
{
    if(sll) delete sll;
}

void App::processInput()
{
    sf::Event event;
    while (window.pollEvent(event))
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                if(event.key.code==sf::Keyboard::I)
                    sll->insertFront(2);
                break;
            case sf::Event::Closed:
                window.close();
                break;
        }
}

void App::draw()
{
    window.clear();
    window.draw(bgSprite);
    sll->draw();
    window.display();
}

void App::run()
{
    sll->randomList(4);
    sll->makeList();
    while (window.isOpen())
    {
        processInput();
        draw();
    }
}
