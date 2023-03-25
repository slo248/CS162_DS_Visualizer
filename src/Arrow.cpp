#include <Arrow.hpp>

Arrow::Arrow()
{
    mConvex.setPointCount(7);
    mConvex.setFillColor(DEFAULT_COLOR);

    mConvex.setPoint(0,sf::Vector2f(0,HEIGHT_EACH));
    mConvex.setPoint(1,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH));
    mConvex.setPoint(2,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH*3.f/2.f));
    mConvex.setPoint(3,sf::Vector2f(FIRST_WIDTH+SECOND_WIDTH,HEIGHT_EACH*3.f/4.f));
    mConvex.setPoint(4,sf::Vector2f(FIRST_WIDTH,0));
    mConvex.setPoint(5,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH/2.f));
    mConvex.setPoint(6,sf::Vector2f(0,HEIGHT_EACH/2.f)); 
}

void Arrow::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mConvex,states);
}
