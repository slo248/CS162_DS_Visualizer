#pragma once

#include <SFML/Graphics.hpp>

class App
{
    public:
                App();
        void    run();

    private:
        sf::RenderWindow            mWindow;
};