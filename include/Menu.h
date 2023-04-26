#include "Global.h"
#include "Button.h"
#include <queue>

namespace DS
{
    enum Type
    {
        SLL,
        DLL,
        CLL,
        STACK,
        QUEUE,
        SARR,
        DARR,
        NUM_DS
    };
}

class Menu: public sf::Drawable
{
public:
    Menu(sf::Font* sanf, sf::Vector2f windowSize);
    int getCommand();
    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Texture btnTexture;
    sf::Text    title, subtitle;
    std::vector<Button> DS;
    std::queue<int>    cmdQueue;
};