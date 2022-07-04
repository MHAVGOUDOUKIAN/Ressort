#ifndef SPRING_HPP
#define SPRING_HPP

#include <SFML/Graphics.hpp>
#include <Application/Masse.hpp>
#include <Application/Support.hpp>

class Spring : public sf::Drawable {
    public:
        Spring();
        ~Spring();
        void update(sf::Time deltaTime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        
        void setPosInit(float x, float y);
        void setPosFinal(float x, float y);
        void setk(float);
        void setlo(float);
        const sf::Vector2f& posInit(void);
        const sf::Vector2f& posFinal(void);
        float k();
        float lo();

    public:
        float m_k;
        float m_lo;
        
        Masse m_mass;
        Support m_support;
        sf::RectangleShape m_shape;
};

#endif