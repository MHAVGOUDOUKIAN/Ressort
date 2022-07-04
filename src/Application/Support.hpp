#ifndef SUPPORT_HPP
#define SUPPORT_HPP

#include <SFML/Graphics.hpp>

class Support : public sf::Drawable {
    public:
        Support();
        ~Support();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
        void setPos(float x, float y) { m_pos = sf::Vector2f(x,y); }
        const sf::Vector2f& pos(void) { return m_pos; }

    public:
        sf::Vector2f m_pos;
        sf::RectangleShape m_shape;
};

#endif