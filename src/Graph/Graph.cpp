#include "Graph.h"

Graph::Graph(sf::RenderWindow *window, sf::Font *sanf):
    window(window)
{
    text=new sf::Text("", *sanf, 23);
    clear();
}

void Graph::clear()
{
    curFrame=curStep=0;
    nFrames.clear();
    drawFunc.clear();
    dir=FORWARD;
    type=AUTO;
}

void Graph::finishAllSteps()
{
    if(nFrames.empty()) return;
    while (curFrame < nFrames[curStep] || curStep < nFrames.size() - 1) {
        for (auto draw : drawFunc[curStep]) 
            draw(curFrame / (float)nFrames[curStep]);
        if (curFrame == nFrames[curStep] && curStep + 1 < nFrames.size()){
            curStep++;
            curFrame = 0;
        }
        if (curFrame < nFrames[curStep]) curFrame++;
    }
    curFrame=curStep=0;
    nFrames.clear();
    drawFunc.clear();
    // clear();
}

void Graph::addStep(int frames)
{
    nFrames.push_back(frames);
    drawFunc.push_back(std::vector<functor>());
}

void Graph::goToBegin()
{
    if(nFrames.empty()) return;

    while (curFrame > 0 || curStep > 0) {
        for (auto draw : drawFunc[curStep]) 
            draw(curFrame / (float)nFrames[curStep]);
        if (curFrame == 0 && curStep > 0){
            curStep--;
            curFrame = nFrames[curStep];
        }
        if (curFrame > 0) curFrame--;
    }

    setVisualType(STEP_BY_STEP);
    setVisualDir(BACKWARD);
}

void Graph::goToEnd()
{
    if(nFrames.empty()) return;

    while (curFrame < nFrames[curStep] || curStep < nFrames.size() - 1) {
        for (auto draw : drawFunc[curStep]) 
            draw(curFrame / (float)nFrames[curStep]);
        if (curFrame == nFrames[curStep] && curStep + 1 < nFrames.size()){
            curStep++;
            curFrame = 0;
        }
        if (curFrame < nFrames[curStep]) curFrame++;
    }

    setVisualType(STEP_BY_STEP);
    setVisualDir(FORWARD);
}

bool Graph::isDoneAllSteps()
{
    if(nFrames.empty()) return true;
    return curStep==nFrames.size()-1 && curFrame==nFrames[curStep];
}

void Graph::nextStep()
{
    dir=FORWARD;

    if(nFrames.empty()) return;

    if(curFrame==nFrames[curStep] && curStep<nFrames.size()-1){
        curStep++;
        curFrame=0;
        for(auto draw: drawFunc[curStep])
            draw(curFrame/(float)nFrames[curStep]);
    }
}

void Graph::prevStep()
{
    dir=BACKWARD;

    if(nFrames.empty()) return;

    if(curFrame==0 && curStep>0){
        curStep--;
        curFrame=nFrames[curStep];
        for(auto draw: drawFunc[curStep])
            draw(curFrame/(float)nFrames[curStep]);
    }
}

void Graph::setVisualDir(VisualDir d)
{
    dir=d;
}

void Graph::setVisualType(VisualType t)
{
    type=t;
}

void Graph::draw(Node *node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircle, node, window, figure.circle, inColor, outColor, text, numColor));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquare, node, window, figure.square, inColor, outColor, text, numColor));
}

void Graph::drawGrow(Node *node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleGrow, node, window, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareGrow, node, window, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawShrink(Node *node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleShrink, node, window, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareShrink, node, window, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawFadeIn(Node *node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleFadeIn, node, window, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareFadeIn, node, window, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawFadeOut(Node *node, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleFadeOut, node, window, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareFadeOut, node, window, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawMove(Node *node, NodeType type, sf::Vector2f src, sf::Vector2f dest, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleMove, node, window, src, dest, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareMove, node, window, src, dest, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawMove(Node *node, NodeType type, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    if(type==NodeType::CIRCLE)
        drawFunc.back().push_back(std::bind(&Node::drawCircleMove, node, window, node->position, node->position+delta, figure.circle, inColor, outColor, text, numColor, std::placeholders::_1));
    else
        drawFunc.back().push_back(std::bind(&Node::drawSquareMove, node, window, node->position, node->position+delta, figure.square, inColor, outColor, text, numColor, std::placeholders::_1));
}

void Graph::drawSubscript(Node *node, std::string str, sf::Color textColor)
{
    drawFunc.back().push_back(std::bind(&Node::drawSubscript, node, window, text, str, textColor));
}

void Graph::draw(List<Node> *list, NodeType type, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    draw(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::draw(List<Node> *list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        draw(list, type, i, inColor, outColor, numColor);
}

void Graph::draw(List<Node> *list, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    draw(list, type, 0, list->size()-1, inColor, outColor, numColor);
}

void Graph::drawGrow(List<Node> *list, NodeType type, int i, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawGrow(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::drawGrow(List<Node> *list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        drawGrow(list, type, i, inColor, outColor, numColor);
}

void Graph::drawGrow(List<Node> *list, NodeType type, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawGrow(list, type, 0, list->size()-1, inColor, outColor, numColor);
}

void Graph::drawMove(List<Node> *list, NodeType type, int i, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawMove(&list->begin()->getNext(i)->data, type, delta, inColor, outColor, numColor);
}

void Graph::drawMove(List<Node> *list, NodeType type, int from, int to, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        drawMove(list, type, i, delta, inColor, outColor, numColor);
}

void Graph::drawMove(List<Node> *list, NodeType type, sf::Vector2f delta, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    drawMove(list, type, 0, list->size()-1, delta, inColor, outColor, numColor);
}

void Graph::drawFadeIn(List<Node> *list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        drawFadeIn(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::drawFadeOut(List<Node> *list, NodeType type, int from, int to, sf::Color inColor, sf::Color outColor, sf::Color numColor)
{
    for(int i=from; i<=to; i++)
        drawFadeOut(&list->begin()->getNext(i)->data, type, inColor, outColor, numColor);
}

void Graph::draw(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::draw, arrow, window, figure.arrow, color));
}

void Graph::drawGrow(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawGrow, arrow, window, figure.arrow, color, std::placeholders::_1));
}

void Graph::drawShrink(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawShrink, arrow, window, figure.arrow, color, std::placeholders::_1));
}

void Graph::drawFadeIn(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawFadeIn, arrow, window, figure.arrow, color, std::placeholders::_1));
}

void Graph::drawFadeOut(Arrow *arrow, sf::Color color)
{
    drawFunc.back().push_back(std::bind(&Arrow::drawFadeOut, arrow, window, figure.arrow, color, std::placeholders::_1));
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
    draw(list, 0, list->size()-1, color);
}

void Graph::drawGrow(List<Arrow> *list, int i, sf::Color color)
{
    drawGrow(&list->begin()->getNext(i)->data, color);
}

void Graph::drawGrow(List<Arrow> *list, int from, int to, sf::Color color)
{
    for(int i=from; i<=to; i++)
        drawGrow(list, i, color);
}

void Graph::drawGrow(List<Arrow> *list, sf::Color color)
{
    drawGrow(list, 0, list->size()-1, color);
}

void Graph::drawFadeIn(List<Arrow> *list, int from, int to, sf::Color color)
{
    for(int i=from; i<=to; i++)
        drawFadeIn(&list->begin()->getNext(i)->data, color);
}

void Graph::drawFadeOut(List<Arrow> *list, int from, int to, sf::Color color)
{
    for(int i=from; i<=to; i++)
        drawFadeOut(&list->begin()->getNext(i)->data, color);
}

void Graph::draw(CodeBox *codeBox, int pos)
{
    drawFunc.back().push_back(std::bind(&CodeBox::draw, codeBox, window, pos));
}

void Graph::draw()
{
    if(nFrames.empty()) return;

    for(functor f : drawFunc[curStep]){
        text->setScale(1,1);
        figure.circle->setScale(1,1);
        figure.arrow->setScale(1,1);
        f(1.f*curFrame/nFrames[curStep]);
    }

    if(dir==FORWARD){
        if(curFrame<nFrames[curStep])
            curFrame++;
        else if(type==AUTO && curStep<drawFunc.size()-1){
            curFrame=0;
            curStep++;
        }
    }
    else{
        if(curFrame>0)
            curFrame--;
        else if(type==AUTO && curStep>0){
            curStep--;
            curFrame=nFrames[curStep];
        }
    }
}
