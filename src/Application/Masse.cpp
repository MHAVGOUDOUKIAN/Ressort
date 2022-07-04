#include <Application/Masse.hpp>

Masse::Masse() : m_mass(10), m_pos(100,110), m_vit(0,0), m_acc(0,0) {
    m_shape.setFillColor(sf::Color::Red);
    m_shape.setPosition(m_pos);
    m_shape.setSize(sf::Vector2f(50,50));
}

Masse::~Masse() {}

void Masse::update(sf::Time deltaTime) {
    m_vit +=  m_acc * deltaTime.asSeconds() ;
    m_pos +=  m_vit * deltaTime.asSeconds() ;

    m_shape.setPosition(m_pos);
}

void Masse::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_shape);
}