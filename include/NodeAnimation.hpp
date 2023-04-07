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
            if(mStr=="pHead/vtx") node.getNext()->setSubscript("");
        }
    };
}