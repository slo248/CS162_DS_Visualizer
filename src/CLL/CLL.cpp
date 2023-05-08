#include "CLL.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

CLL::CLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS):
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

CLL::~CLL()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void CLL::draw()
{
    graph.draw();
}

bool CLL::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void CLL::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void CLL::play()
{
    graph.setVisualType(AUTO);
    graph.setVisualDir(FORWARD);
}

void CLL::nextStep()
{
    graph.nextStep();
}

void CLL::prevStep()
{
    graph.prevStep();
}

void CLL::goToBegin()
{
    graph.goToBegin();
}

void CLL::goToEnd()
{
    graph.goToEnd();
}
