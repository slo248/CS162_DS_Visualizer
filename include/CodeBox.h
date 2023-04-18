#ifndef CODE_BOX_H
#define CODE_BOX_H

#include "Global.h"

class CodeBox
{
public:
    const float         WIDTH = 600;
    const float         HEIGHT = 43.75;
    const float         CHAR_SIZE=23;
    const int           MAX_LINE = 8;
    const sf::Color     BG_COLOR = sf::Color(192, 192, 192, 160);
    const sf::Color     CUR_LINE = sf::Color(255, 217, 61);
    const sf::Color     TEXT_COLOR = BLACK;

    CodeBox(sf::Font* font);
    void loadFromFile(std::string path);
    void draw(sf::RenderWindow* window, int pos);
private:
    sf::RectangleShape rect;
    sf::Text text;
    std::vector<std::string> code;
};

#endif // CODE_BOX_H