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
