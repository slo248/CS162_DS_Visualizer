#include "Entity.hpp"

unsigned int Entity::getCategory() const
{
    return Category::None;
}

sf::Vector2f Entity::getVelocity() const
{
    return mVelocity;
}

void Entity::setVelocity(sf::Vector2f velocity)
{
    mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
    mVelocity.x = vx;
    mVelocity.y = vy;
}

void Entity::accelerate(sf::Vector2f velocity)
{
    mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
    mVelocity.x += vx;
    mVelocity.y += vy;
}

void Entity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
}

void Entity::updateCurrent(sf::Time dt)
{
    move(mVelocity*dt.asSeconds());
}
