#ifndef CODE_BOX_H
#define CODE_BOX_H

#include "HNeed.h"

class CodeBox
{
private:
    sf::RectangleShape* rect;
    sf::Text* text;
    std::vector<std::string> code;
};

#endif // CODE_BOX_H