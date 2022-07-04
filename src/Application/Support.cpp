#include <Application/Support.hpp>

Support::Support() : m_pos(350,150) {
    m_shape.setFillColor(sf::Color::Blue);
    m_shape.setPosition(m_pos);
    m_shape.setSize(sf::Vector2f(20,20));
}

Support::~Support() {}

void Support::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_shape);
}