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