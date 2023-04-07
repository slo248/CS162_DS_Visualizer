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
        sf::Vector2f dest;
        SceneNode* layer;
        Move(sf::Vector2f dest, SceneNode* layer):
            dest(dest),layer(layer){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setPosition(node.getPosition()+(dest-node.getPosition())*factor);
            sf::Vector2f delta=dest-node.getPosition();
            // change next arrow
            {
                Arrow* curArrow=node.getArrowNext();
                if(curArrow){
                    std::unique_ptr<Arrow> newArr=node.makeArrow(node.getNext());
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
                    newArr->setScale(1,1);
                    layer->detachChild(*curArrow);
                    node.setArrowNext(newArr.get());
                    layer->attachChild(std::move(newArr));
                }
            }
        }
    };
}