#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <SFML/Graphics.hpp>

class KeyBoardObserver {
    public:
        virtual ~KeyBoardObserver() {}
        virtual void notify(sf::Keyboard::Key key, bool pressed) =0;
        virtual void reset() {}
};

class MouseObserver {
    public:
        virtual ~MouseObserver() {}
        virtual void notify(sf::Mouse::Button mouse, sf::Vector2i& pos, bool clicked) =0;
        virtual void reset() {}
};

class EventObserver {
    public:
        virtual ~EventObserver() {}
        virtual void notify(sf::Event event) =0;
        virtual void reset() {}
};

#endif