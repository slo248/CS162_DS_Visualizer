#include "DLL.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

DLL::DLL(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS, sf::CircleShape* circle, ArrowFigure *arrowFig):
    FPS(FPS),
    window(window),
    codeBox(cons),
    sanf(sanf),
    cons(cons),
    graph(window, sanf, circle, arrowFig)
{
    graph.clear();
    graph.setVisualType(AUTO);

    randomList(4);
    makeList();
}

DLL::~DLL()
{
    for(Node *node : deletedNode) delete node;
    for(Arrow *arrow : deletedArrow) delete arrow;
}

void DLL::draw()
{
    graph.draw();
}

bool DLL::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void DLL::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void DLL::play()
{
    graph.setVisualType(AUTO);
    graph.setVisualDir(FORWARD);
}

void DLL::nextStep()
{
    graph.nextStep();
}

void DLL::prevStep()
{
    graph.prevStep();
}

void DLL::goToBegin()
{
    graph.goToBegin();
}

void DLL::goToEnd()
{
    graph.goToEnd();
}
