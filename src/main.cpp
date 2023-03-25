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

        App app(mFonts.get(Fonts::ID::Times));
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}