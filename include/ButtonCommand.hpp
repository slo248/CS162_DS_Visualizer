#pragma once

#include <Button.hpp>

struct ButtonAppear
{
    void operator() (Button& button, sf::Time dt) const{
        button.setScale(1.f,1.f);
    }
};

struct ButtonDisappear
{
    void operator() (Button& button, sf::Time dt) const{
        button.setScale(0.f,0.f);
    }
};