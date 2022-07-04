#ifndef APP_HPP
#define APP_HPP

#include <SFML/Graphics.hpp>

#include <Engine/Observer.hpp>
#include <Engine/EventHandler.hpp>
#include <Engine/Network.hpp>

#include <Application/Masse.hpp>
#include <Application/Support.hpp>
#include <Application/Resolver.hpp>

#include <vector>
#include <iostream>

class Engine;

class App : public sf::Drawable, public MouseObserver, public KeyBoardObserver{
    public:
        App();
        virtual ~App();
        void update(sf::Time deltaTime);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void notify(sf::Mouse::Button, sf::Vector2i&, bool clicked);
        virtual void notify(sf::Keyboard::Key key, bool pressed);

    private:
        Masse m_masse;
        Support m_support;

};

#endif