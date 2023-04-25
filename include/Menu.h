#include "Global.h"
#include "Button.h"

class Menu: public sf::Drawable
{
public:
    Menu(sf::Font* sanf, sf::Vector2f windowSize);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Texture btnTexture;
    sf::Text    title, subtitle;
    std::vector<Button> DS;
};