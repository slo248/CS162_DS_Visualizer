#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class SceneNode : 
    public  sf::Drawable,
    public  sf::Transformable,
    private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;

    public:
        void    attachChild(Ptr& child);  
        Ptr     detachChild(const SceneNode& child);
        sf::Transform   getWorldTransform() const;
        sf::Vector2f    getWorldPosition() const;

    private:
        SceneNode*              mParent;
        std::vector<Ptr>        mChildren;
};