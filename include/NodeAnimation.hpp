#pragma once

#include <Node.hpp>
#include <iostream>

namespace NodeAnimation
{
    struct ChangeColor
    {
        sf::Color mColor;
        ChangeColor(sf::Color color):mColor(color){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setBGColor(mColor);
        }
    };
 
    struct ChangeSubscript
    {
        std::string mStr;
        ChangeSubscript(std::string str):mStr(str){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setSubscript(mStr);
        }
    };

    struct BecomeHead
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setHead(true);
            node.getNext()->setHead(false);
            ChangeSubscript("pHead/vtx")(node,elapsedTime,duration);
            ChangeSubscript("")(*node.getNext(),elapsedTime,duration);
        }
    };

    struct Move
    {
        sf::Vector2f src;
        sf::Vector2f dest;
        SceneNode* layer;
        Move(sf::Vector2f src,sf::Vector2f dest, SceneNode* layer):
            src(src),dest(dest),layer(layer){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setPosition(src+(dest-src)*factor);
            sf::Vector2f delta=dest-node.getPosition();
            float dist=sqrt(delta.x*delta.x+delta.y*delta.y);
            // change next arrow
            {
                Arrow* curArrow=node.getArrowNext();
                if(curArrow){
                    std::unique_ptr<Arrow> newArr=node.makeArrow(node.getNext());
                    if(dist<=2*NodeConfig::RADIUS)
                        newArr->setScale(0,0);
                    else
                        newArr->setScale(1,1);
                    layer->detachChild(*curArrow);
                    node.setArrowNext(newArr.get());
                    layer->attachChild(std::move(newArr));
                }
            }
            // change previous arrow
            {
                Arrow* curArrow=node.getArrowPrev();
                if(curArrow){
                    std::unique_ptr<Arrow> newArr=node.makeArrow(node.getPrev());
                    if(dist<=2*NodeConfig::RADIUS)
                        newArr->setScale(0,0);
                    else
                        newArr->setScale(1,1);
                    layer->detachChild(*curArrow);
                    node.setArrowNext(newArr.get());
                    layer->attachChild(std::move(newArr));
                }
            }
        }
    };
}