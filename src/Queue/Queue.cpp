#include "Queue.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

Queue::Queue(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    codeBox(cons),
    sanf(sanf),
    cons(cons),
    graph(window, sanf)
{
    graph.clear();
    graph.setVisualType(AUTO);

    randomList(4);
    makeList();
}

Queue::~Queue()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void Queue::draw()
{
    graph.draw();
}

bool Queue::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void Queue::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void Queue::play()
{
    graph.setVisualType(AUTO);
}

void Queue::nextStep()
{
    graph.nextStep();
}

void Queue::prevStep()
{
    graph.prevStep();
}

void Queue::goToBegin()
{
    graph.goToBegin();
}

void Queue::goToEnd()
{
    graph.goToEnd();
}