#ifndef MASSE_HPP
#define MASSE_HPP

#include <SFML/Graphics.hpp>

class Masse : public sf::Drawable {
    public:
        Masse();
        ~Masse();
        void update(sf::Time deltaTime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
    public:
        int m_mass;
        sf::Vector2f m_pos;
        sf::Vector2f m_vit;
        sf::Vector2f m_acc;
        sf::RectangleShape m_shape;
};

#endif