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
        const float TimePerFrame=1.f/60.f;

    private:
        sf::RenderWindow            mWindow;

    private:
        void                        processInput();
        void                        update();
        void                        render();
};