#ifndef APP_H
#define APP_H

#include "Global.h"

class App
{
public:
    App();

    // main loop
    void processInput();
    
    //

private:
    sf::RenderWindow    window;
    sf::Font            cons, sanf;
    sf::Texture         bgImage;
};

#endif // APP_H