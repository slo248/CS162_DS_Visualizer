#ifndef CLL_CONTROL_H
#define CLL_CONTROL_H

#include "Control.h"

class CLL_Control : public Control
{
public:
    CLL_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // CLL_CONTROL_H