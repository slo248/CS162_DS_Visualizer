#include <App.hpp>
#include <iostream>

int main()
{
    try
    {
        App app;
        app.run();
    }
    catch (std::exception& e)
    {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
    return 0;
}