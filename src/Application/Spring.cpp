#include <Application/Spring.hpp> 

Spring::Spring(Masse* m1, Masse* m2, float k, float lo):m_k(k), m_lo(lo), m_m1(m1),
m_m2(m2), m_vertex(sf::Lines, 2) {
    m_vertex[0].color = sf::Color::Black;
    m_vertex[1].color = sf::Color::Black;

    m_vertex[0].position = m_m1->m_centerPos;
    m_vertex[1].position = m_m2->m_centerPos;
}

Spring::~Spring() {}

void Spring::update(sf::Time deltaTime) {
    m_vertex[0].position = m_m1->m_centerPos;
    m_vertex[1].position = m_m2->m_centerPos;
}

void Spring::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_vertex);
}