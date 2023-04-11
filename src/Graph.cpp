#include "Graph.h"

Graph::Graph(sf::RenderWindow *window, sf::Font *sanf, sf::CircleShape *hCircle, sf::CircleShape *sCircle, ArrowFigure* arrowFig):
    window(window), hCircle(hCircle), sCircle(sCircle), arrowFig(arrowFig)
{
    text=new sf::Text("", *sanf, 23);
    clear();
}

void Graph::clear()
{
    curFrame=curStep=0;
    nFrames.clear();
    drawFunc.clear();
}

void Graph::addStep(int frames)
{
    nFrames.push_back(frames);
    drawFunc.push_back(std::vector<functor>());
}

void Graph::draw(Node *node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawFunc.back().push_back(std::bind(&Node::draw, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawGrow(Node *node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawFunc.back().push_back(std::bind(&Node::drawGrow, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawShrink(Node *node, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawFunc.back().push_back(std::bind(&Node::drawShrink, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::draw(List<Node> *list, int i, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    draw(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::draw(List<Node> *list, int from, int to, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        draw(list, i, type, inColor, outColor, numColor);
}

void Graph::draw(List<Node> *list, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    draw(list, 0, list->getSize()-1, type, inColor, outColor, numColor);
}

void Graph::drawGrow(List<Node> *list, int i, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawGrow(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::drawGrow(List<Node> *list, int from, int to, CircleType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        drawGrow(list, i, type, inColor, outColor, numColor);
}

void Graph::draw(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::draw, arrow, window, arrowFig, color, std::placeholders::_1));
}

void Graph::drawGrow(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawGrow, arrow, window, arrowFig, color, std::placeholders::_1));
}

void Graph::drawShrink(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawShrink, arrow, window, arrowFig, color, std::placeholders::_1));
}

void Graph::draw(List<Arrow> *list, int i, sf::Color color)
{
    draw(&list->begin()->getNext(i)->data, color);
}

void Graph::draw(List<Arrow> *list, int from, int to, sf::Color color)
{
    for(int i=from; i<=to; i++)
        draw(list, i, color);
}

void Graph::draw(List<Arrow> *list, sf::Color color)
{
    draw(list, 0, list->getSize()-1, color);
}

void Graph::draw()
{
    if(nFrames.empty()) return;

    for(functor f : drawFunc[curStep])
        f(1.f*curFrame/nFrames[curStep]);

    if(curFrame<nFrames[curStep])
        curFrame++;
    else if(curStep<drawFunc.size()-1){
        curFrame=0;
        curStep++;
    }
}
