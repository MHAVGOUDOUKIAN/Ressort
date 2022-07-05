#ifndef SPRING_HPP
#define SPRING_HPP

#include <SFML/Graphics.hpp>
#include <Application/Masse.hpp>
#include <Application/Support.hpp>

class Spring : public sf::Drawable {
    public:
        Spring(Masse* m_m1, Masse* m_m2, float k, float lo);
        ~Spring();
        void update(sf::Time deltaTime);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        float m_k;
        float m_lo;
        Masse* m_m1;
        Masse* m_m2;
        
        
        sf::VertexArray m_vertex;
};

#endif