#include <App.hpp>
#include <ResourceHolder.hpp>
#include <iostream>

FontHolder mFonts;

int main()
{
    system("cls");
    try
    {
        mFonts.load(Fonts::ID::Times,"media/font/times.ttf");

        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        App app(mFonts.get(Fonts::ID::Times),settings);
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}