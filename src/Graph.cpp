#include "Graph.h"

Graph::Graph(sf::RenderWindow *window, sf::Font *sanf, sf::CircleShape *hCircle, sf::CircleShape *sCircle):
    window(window), hCircle(hCircle), sCircle(sCircle)
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

void Graph::draw(Node *node, CircleType type, sf::Color inColor, sf::Color outColor)
{
    drawFunc.back().push_back(std::bind(&Node::draw, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, std::placeholders::_1));
}

void Graph::drawGrow(Node *node, CircleType type, sf::Color inColor, sf::Color outColor)
{
    drawFunc.back().push_back(std::bind(&Node::drawGrow, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, std::placeholders::_1));
}

void Graph::drawShrink(Node *node, CircleType type, sf::Color inColor, sf::Color outColor)
{
    drawFunc.back().push_back(std::bind(&Node::drawShrink, node, window, type==Hollow?hCircle:sCircle, inColor, outColor, std::placeholders::_1));
}

void Graph::draw(List<Node> *list, int i, CircleType type, sf::Color inColor, sf::Color outColor)
{
    draw(&list->begin()->getNext(i)->data, type, inColor, outColor);
}

void Graph::draw(List<Node> *list, int from, int to, CircleType type, sf::Color inColor, sf::Color outColor)
{
    for(int i=from; i<=to; i++)
        draw(list, i, type, inColor, outColor);
}

void Graph::draw(List<Node> *list, CircleType type, sf::Color inColor, sf::Color outColor)
{
    draw(list, 0, list->getSize()-1, type, inColor, outColor);
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
