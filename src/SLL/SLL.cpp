#include "SLL.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

SLL::SLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS):
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
    graph.setVisualDir(FORWARD);
}

void SLL::nextStep()
{
    graph.nextStep();
}

void SLL::prevStep()
{
    graph.prevStep();
}

void SLL::goToBegin()
{
    graph.goToBegin();
}

void SLL::goToEnd()
{
    graph.goToEnd();
}
