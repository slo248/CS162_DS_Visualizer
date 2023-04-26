#ifndef SArr_CONTROL_H
#define SArr_CONTROL_H

#include "Control.h"

class SArr_Control : public Control
{
public:
    SArr_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // SArr_CONTROL_H