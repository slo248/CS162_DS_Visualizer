#ifndef DLL_CONTROL_H
#define DLL_CONTROL_H

#include "Control.h"

class DLL_Control : public Control
{
public:
    DLL_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // DLL_CONTROL_H