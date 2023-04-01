#pragma once

#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>

namespace Category{
    enum Type{
        None = 0,
        Node = 1 << 0,
        Arrow = 1 << 1,
        TextBoxFixed = 1 << 3,
        TextBoxDynamic = 1 << 4,
        Button = 1 << 5,
        All = Node | Arrow | TextBoxFixed | TextBoxDynamic | Button
    };
}

class SceneNode : 
    public  sf::Drawable,
    public  sf::Transformable,
    private sf::NonCopyable
{
    public:
        typedef std::unique_ptr<SceneNode> Ptr;

    public:
        void            attachChild(Ptr child);  
        Ptr             detachChild(const SceneNode& child);
        sf::Transform   getWorldTransform() const;
        sf::Vector2f    getWorldPosition() const;
        void            clearChildren();
        virtual int     getCategory() const;

    private:
        virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        SceneNode*              mParent;
        std::vector<Ptr>        mChildren;
};