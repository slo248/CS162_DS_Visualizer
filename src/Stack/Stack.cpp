#include "Stack.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

Stack::Stack(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
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

Stack::~Stack()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void Stack::draw()
{
    graph.draw();
}

bool Stack::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void Stack::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void Stack::play()
{
    graph.setVisualType(AUTO);
}

void Stack::nextStep()
{
    graph.nextStep();
}

void Stack::prevStep()
{
    graph.prevStep();
}

void Stack::handleEvent(sf::Event &event)
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
