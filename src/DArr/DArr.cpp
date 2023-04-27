#include "DArr.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"
#include "Config.h"

using namespace Config::DArr;

DArr::DArr(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS):
    FPS(FPS),
    window(window),
    codeBox(cons),
    sanf(sanf),
    cons(cons),
    graph(window, sanf)
{
    graph.clear();
    graph.setVisualType(AUTO);

    num.position = START_POSITION_N;

    randomList(4);
    makeList();

    for(int i=0; i<MAX_NODE; i++)
        tmpListNode.pushBack(-1);
}

DArr::~DArr()
{
    for(Node *node : deletedNode) delete node;
}

void DArr::draw()
{
    graph.draw();
}

bool DArr::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void DArr::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void DArr::play()
{
    graph.setVisualType(AUTO);
    graph.setVisualDir(FORWARD);
}

void DArr::nextStep()
{
    graph.nextStep();
}

void DArr::prevStep()
{
    graph.prevStep();
}

void DArr::goToBegin()
{
    graph.goToBegin();
}

void DArr::goToEnd()
{
    graph.goToEnd();
}
