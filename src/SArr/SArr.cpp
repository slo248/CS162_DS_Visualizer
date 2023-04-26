#include "SArr.h"
#include "Random.h"
#include "Config.h"
#include "Button.h"

SArr::SArr(sf::RenderWindow *window, sf::Font *sanf, sf::Font* cons, int FPS):
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

SArr::~SArr()
{
    for(Node *node : deletedNode) delete node;
}

void SArr::draw()
{
    graph.draw();
}

bool SArr::isDoneAllSteps()
{
    return graph.isDoneAllSteps();
}

void SArr::pause()
{
    graph.setVisualType(STEP_BY_STEP);
}

void SArr::play()
{
    graph.setVisualType(AUTO);
    graph.setVisualDir(FORWARD);
}

void SArr::nextStep()
{
    graph.nextStep();
}

void SArr::prevStep()
{
    graph.prevStep();
}

void SArr::goToBegin()
{
    graph.goToBegin();
}

void SArr::goToEnd()
{
    graph.goToEnd();
}
