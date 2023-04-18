#ifndef SLL_CONTROL_H
#define SLL_CONTROL_H

#include "Control.h"

class SLL_Control : 
    public Control,
    public sf::Drawable
{
public:
    SLL_Control(sf::Font* font);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    sf::Font* mFont;

    void genOptions();
    void genSuboptions();
};

#endif // SLL_CONTROL_H