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
        Move(sf::Vector2f src,sf::Vector2f dest):
            src(src),dest(dest){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setPosition(src+(dest-src)*factor);
            // change next arrow
            {
                Arrow* curArrow=node.getArrowNext();
                if(curArrow){
                    std::unique_ptr<Arrow> newArr=node.makeArrow(node.getNext());
                    curArrow->copy(newArr.get());
                    curArrow->setOrigin(newArr->getOrigin());
                    curArrow->setPosition(newArr->getPosition());
                    curArrow->rotate(newArr->getRotation());
                }
            }
            // change previous arrow
            {
                Arrow* curArrow=node.getArrowPrev();
                if(curArrow){
                    std::unique_ptr<Arrow> newArr=node.makeArrow(node.getPrev());
                    curArrow->copy(newArr.get());
                    curArrow->setOrigin(newArr->getOrigin());
                    curArrow->setPosition(newArr->getPosition());
                    curArrow->rotate(newArr->getRotation());
                }
            }
        }
    };
}