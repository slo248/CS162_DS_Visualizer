#ifndef Queue_CONTROL_H
#define Queue_CONTROL_H

#include "Control.h"

class Queue_Control : public Control
{
public:
    Queue_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // Queue_CONTROL_H