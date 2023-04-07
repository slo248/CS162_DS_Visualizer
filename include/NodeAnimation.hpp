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
 
    struct changeSubscript
    {
        std::string str;
        changeSubscript(std::string str):str(str){}
        void operator() (Node& node, sf::Time elapsedTime, sf::Time duration) const
        {
            node.setSubscript(str);
        }
    };
}