#pragma once

#include <SFML/Graphics.hpp>

class App
{
    public:
                App();
        void    run();

    private:
        const int   windowWidth=1000;
        const int   windowHeight=1000;

    private:
        sf::RenderWindow            mWindow;
};