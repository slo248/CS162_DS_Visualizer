#include "Button.h"

Button::~Button()
{
    delete rect;
    delete text;
}