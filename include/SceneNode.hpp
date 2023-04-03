#pragma once

#include <Command.hpp>
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
        ButtonCreate = 1 << 5,
        ButtonInsert = 1 << 6,
        ButtonUpdate = 1 << 7,
        ButtonRemove = 1 << 8,
        ButtonSearch = 1 << 9,
        AllButton = ButtonCreate | ButtonInsert | ButtonUpdate | ButtonRemove | ButtonSearch,
        All = Node | Arrow | TextBoxFixed | TextBoxDynamic | AllButton
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
        void            onCommand(const Command& command, sf::Time dt);
        void            update(sf::Time dt);

    private:
        virtual void    draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void    drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void            drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void    updateCurrent(sf::Time dt);
        void            updateChildren(sf::Time dt);

    private:
        SceneNode*              mParent;
        std::vector<Ptr>        mChildren;
};