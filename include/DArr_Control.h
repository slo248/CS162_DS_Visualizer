#ifndef DArr_CONTROL_H
#define DArr_CONTROL_H

#include "Control.h"

class DArr_Control : public Control
{
public:
    DArr_Control(sf::Font* font, sf::Vector2f windowSize);

private:
    void genOptions(sf::Vector2f windowSize);
    void genSuboptions(sf::Vector2f windowSize);
};

#endif // DArr_CONTROL_H