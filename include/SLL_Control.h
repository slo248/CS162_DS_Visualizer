#ifndef SLL_CONTROL_H
#define SLL_CONTROL_H

#include "Control.h"

class SLL_Control : public Control
{
public:
    SLL_Control(sf::Font* font);
private:
    sf::Font* mFont;

    void genOptions();
    void genSuboptions();
};

#endif // SLL_CONTROL_H