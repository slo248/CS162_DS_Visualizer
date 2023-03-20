#include "App.hpp"

App::App():
    mWindow(sf::VideoMode(windowWidth,windowHeight,sf::Style::Titlebar|sf::Style::Close),"Data Structure Visualization"),
    mCircle()
{
    mCircle.setPosition(100.f,100.f);
    mCircle.setRadius(10.f);
    mCircle.setFillColor(sf::Color::White);
    mCircle.setOutlineThickness(8.f);
    mCircle.setOutlineColor(sf::Color::Blue);
}

void App::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
        switch(event.type){
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
}

void App::update(sf::Time dt)
{
    
}
