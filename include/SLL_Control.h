#ifndef SLL_CONTROL_H
#define SLL_CONTROL_H

#include "Control.h"

class SLL_Control : 
    public Control,
    public sf::Drawable
{
public:
    SLL_Control(sf::Font* font, sf::Vector2f windowSize);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // SLL_CONTROL_H