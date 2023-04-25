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

    randomList(4);
    makeList();
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

void Stack::goToBegin()
{
    graph.goToBegin();
}

void Stack::goToEnd()
{
    graph.goToEnd();
}

void Stack::peek()
{
    codeBox.loadFromFile("code/Stack/peek.txt");

    graph.addStep(0.5*FPS);
    graph.draw(&codeBox,0);

    if(listNode.empty()) return;

    graph.finishAllSteps();

    // step 1: return head.value
    graph.addStep(0.5*FPS);
    graph.draw(&listNode,WHITE,BLACK,BLACK);
    graph.drawFadeIn(&listNode.begin()->data,ORANGE,ORANGE,WHITE);
    graph.draw(&listArrow,BLACK);
    graph.drawSubscript(&listNode.begin()->data,"head",RED);
    graph.draw(&codeBox,1);
    //
}
