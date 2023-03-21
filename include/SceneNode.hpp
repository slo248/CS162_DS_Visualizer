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
        void    add(Ptr& child);

    private:
        Ptr                     mParent;
        std::vector<Ptr>        mChildren;
};