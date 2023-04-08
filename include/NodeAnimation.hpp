#pragma once

#include <Node.hpp>

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

    struct NormalHead
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            if(node.isHead()){
                node.setBGColor(NodeConfig::INSIDE_COLOR);
                node.setNumColor(NodeConfig::CHAR_COLOR);
                node.setSubscript("pHead");
            }      
        }
    };

    struct Move
    {
        sf::Vector2f delta;
        SceneNode* layer;
        Move(sf::Vector2f delta, SceneNode* layer):
            delta(delta),layer(layer){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            float factor=Motion::Bezier(elapsedTime/duration);
            node.setPosition(node.getPrePos()+delta*factor);
            if(elapsedTime>=duration)
                node.setPrePos(node.getPosition());
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
            // change arrow point to it from the left
            {
                Node* prev=node.getPrev();
                if(prev){
                    Arrow* curArrow=prev->getArrowNext();
                    if(curArrow){
                        std::unique_ptr<Arrow> newArr=prev->makeArrow(&node);
                        newArr->setScale(1,1);
                        layer->detachChild(*curArrow);
                        prev->setArrowNext(newArr.get());
                        layer->attachChild(std::move(newArr));
                    }
                }
            }
            // change arrow point to it from the right
            {
                Node* next=node.getNext();
                if(next){
                    Arrow* curArrow=next->getArrowPrev();
                    if(curArrow){
                        std::unique_ptr<Arrow> newArr=next->makeArrow(&node);
                        newArr->setScale(1,1);
                        layer->detachChild(*curArrow);
                        next->setArrowPrev(newArr.get());
                        layer->attachChild(std::move(newArr));
                    }
                }
            }
        }
    };
}