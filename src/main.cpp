#include "App.h"

int main()
{
    system("cls");
    try
    {
        App app;
        app.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}