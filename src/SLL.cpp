#include "SLL.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, sf::Sprite* bg, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    bg(bg),
    isPause(false),
    codeBox(cons),
    sanf(sanf),
    cons(cons),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();
    graph.setVisualType(STEP_BY_STEP);
}

SLL::~SLL()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void SLL::processInput()
{
    sf::Event event;
    while(window->pollEvent(event))
        switch (event.type){
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::LostFocus:
                isPause=true;
                window->setFramerateLimit(1);
                break;
            case sf::Event::GainedFocus:
                isPause=false;
                window->setFramerateLimit(FPS);
                break;          
        }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !isPause)
        graph.nextStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !isPause)
        graph.prevStep();
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        graph.setVisualType(STEP_BY_STEP);
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        graph.setVisualType(AUTO);
}

void SLL::update()
{
    
}

void SLL::render()
{
    window->clear();

    window->draw(*bg);

    graph.draw();

    window->display();
}

void SLL::run()
{
    sf::Texture texture;
    texture.loadFromFile("media/image/button.png");

    Button btn(sanf,"Create",&texture, sf::Vector2f(200, 400));

    while(window->isOpen()){
        processInput();
        update();
        
        btn.isMouseOver(window);

        window->clear();

        window->draw(*bg);

        window->draw(btn);

        window->display();
    }
}
