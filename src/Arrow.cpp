#include <Arrow.hpp>

Arrow::Arrow(sf::Vector2f dist)
{
    mConvex.setPointCount(7);
    mConvex.setFillColor(DEFAULT_COLOR);
    
    const float length=sqrt(dist.x*dist.x+dist.y*dist.y);
    // std::cout<<length<<' '<<angle<<'\n';

    const float FIRST_WIDTH=length*RATIO_FIRST;
    const float SECOND_WIDTH=length*RATIO_SECOND;
    // std::cout<<FIRST_WIDTH<<' '<<SECOND_WIDTH<<'\n';

    mConvex.setPoint(0,sf::Vector2f(0,HEIGHT_EACH));
    mConvex.setPoint(1,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH));
    mConvex.setPoint(2,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH*3.f/2.f));
    mConvex.setPoint(3,sf::Vector2f(FIRST_WIDTH+SECOND_WIDTH,HEIGHT_EACH*3.f/4.f));
    mConvex.setPoint(4,sf::Vector2f(FIRST_WIDTH,0));
    mConvex.setPoint(5,sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH/2.f));
    mConvex.setPoint(6,sf::Vector2f(0,HEIGHT_EACH/2.f)); 

    sf::FloatRect bounds=mConvex.getLocalBounds();

    mConvex.setOrigin(bounds.left,bounds.top+bounds.height/2);
}

void Arrow::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mConvex,states);
}
