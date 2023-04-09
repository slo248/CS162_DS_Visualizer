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
            if(mColor!=sf::Color::White)
                node.setNumColor(sf::Color::White);
            else
                node.setNumColor(sf::Color::Black);
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

    struct SetSubscriptPreNode
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            Node* pre=node.getPrev();
            if(pre){ 
                pre->setSubscript(pre->getPreSubscript());
                // std::cout<<pre->getSubscript()<<' '<<pre->getPreSubscript()<<std::endl;
            }
        }
    };

    struct AddSubscript
    {
        std::string mStr;
        AddSubscript(std::string str):mStr(str){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            std::string curSub=node.getSubscript();
            std::cout<<node.getSubscript()<<' '<<node.getPreSubscript()<<std::endl;
            if(curSub.empty()) curSub=mStr;
            else curSub+="/"+mStr;
            node.setSubscript(curSub);
            std::cout<<node.getSubscript()<<' '<<node.getPreSubscript()<<std::endl<<std::endl;
        }
    };

    struct BecomeHead
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setHead(true);
            ChangeSubscript("head/vtx")(node,elapsedTime,duration);
            if(node.getNext()){
                node.getNext()->setHead(false);
                ChangeSubscript("")(*node.getNext(),elapsedTime,duration);
            }
        }
    };

    struct NormalHead
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            if(node.isHead()){
                node.setBGColor(NodeConfig::INSIDE_COLOR);
                node.setNumColor(NodeConfig::CHAR_COLOR);
                node.setSubscript("head");
            }      
        }
    };

    struct MakeNew
    {
        MakeNew(){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setSubscript("vtx");
            node.setNumColor(NodeConfig::VTX_NUM_COLOR);
            node.setBGColor(NodeConfig::VTX_BG_COLOR);
        }
    };

    struct MoveChosenToNext
    {
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            Node* next=node.getNext();
            if(next){
                next->setChosen(node.getChosen());
                node.setChosen(Category::None);
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