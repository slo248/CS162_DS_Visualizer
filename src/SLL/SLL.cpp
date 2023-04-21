#include "SLL.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    codeBox(cons),
    sanf(sanf),
    cons(cons),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();
    graph.setVisualType(AUTO);
}

SLL::~SLL()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void SLL::draw()
{
    graph.draw();
}

bool SLL::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void SLL::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void SLL::play()
{
    graph.setVisualType(AUTO);
}

void SLL::nextStep()
{
    graph.nextStep();
}

void SLL::prevStep()
{
    graph.prevStep();
}

void SLL::handleEvent(sf::Event &event)
{
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
                case sf::Keyboard::A:
                    graph.setVisualType(AUTO);
                    break;
                case sf::Keyboard::S:
                    graph.setVisualType(STEP_BY_STEP);
                    break;
                case sf::Keyboard::I:
                    insertFront(1);
                    break;
                case sf::Keyboard::Left:
                    graph.prevStep();
                    break;
                case sf::Keyboard::Right:
                    graph.nextStep();
                    break;
            }
    }
}
