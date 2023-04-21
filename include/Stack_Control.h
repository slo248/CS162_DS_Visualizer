#ifndef STACK_CONTROL_H
#define STACK_CONTROL_H

#include "Control.h"

class Stack_Control : public Control
{
public:
    Stack_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // STACK_CONTROL_H