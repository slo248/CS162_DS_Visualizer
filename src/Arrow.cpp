#include <Arrow.hpp>

Arrow::Arrow(sf::Vector2f dist)
{
    const float length=sqrt(dist.x*dist.x+dist.y*dist.y);

    const float FIRST_WIDTH=length-SECOND_WIDTH;

    mLine.setSize(sf::Vector2f(FIRST_WIDTH,HEIGHT_EACH));
    mLine.setFillColor(DEFAULT_COLOR);
    {
        sf::FloatRect bounds=mLine.getLocalBounds();
        mLine.setOrigin(0,bounds.top+bounds.height/2);
    }

    mTriangle.setPointCount(3);
    mTriangle.setFillColor(DEFAULT_COLOR);
    mTriangle.setPoint(0,sf::Vector2f(0,0));
    mTriangle.setPoint(1,sf::Vector2f(SECOND_WIDTH,HEIGHT_EACH*3.f/2.f));
    mTriangle.setPoint(2,sf::Vector2f(0,HEIGHT_EACH*3.f));
    {
        sf::FloatRect bounds=mTriangle.getLocalBounds();
        mTriangle.setOrigin(0,bounds.top+bounds.height/2);
    }
    mTriangle.move(FIRST_WIDTH,0);

    this->setScale(0,0);
}

void Arrow::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(mLine,states);
    target.draw(mTriangle,states);
}

void Arrow::updateCurrent(sf::Time dt)
{
    if(mVelocity.x*mVelocity.y) mVelocity/=std::sqrt(2.f);
    move(mVelocity*dt.asSeconds());
}

unsigned int Arrow::getCategory() const
{
    unsigned int res=Category::Arrow;
    if(mIsChosen) res|=Category::Chosen;
    return res;
}
