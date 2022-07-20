#include <Application/Resolver.hpp>
#include <Application/utils.hpp>
#include <chrono>
#include <thread>

void Resolver::resolve(Masse& m, const Support& s, sf::Time deltaTime){ // Suppose qu'il y a un ressort entre la masse et le support
    sf::Vector2f m_ctr = sf::Vector2f(m.m_pos.x + m.m_shape.getSize().x/2,m.m_pos.y + m.m_shape.getSize().y/2);
    sf::Vector2f s_ctr = sf::Vector2f(s.m_pos.x + s.m_shape.getSize().x/2,s.m_pos.y + s.m_shape.getSize().y/2);

    float angle = findAngle(s_ctr,m_ctr) + M_PI/2;

    glm::vec2 m_center = glm::vec2(m.m_pos.x + m.m_shape.getSize().x/2,m.m_pos.y + m.m_shape.getSize().y/2);
    glm::vec2 s_center = glm::vec2(s.m_pos.x + s.m_shape.getSize().x/2,s.m_pos.y + s.m_shape.getSize().y/2);

    float long_spring = glm::length(glm::vec2(m_center-s_center)); // Longueur enter masse et support (en pxl, pas en m !)
    //GUILogger::log("Longueur: " + std::to_string(long_spring));

    /**
     * k = coef de rigidité du ressort
     * lo = longueur à vide
     * m= masse
     * g= intensité de pesanteur
     * f = coef d'amortissement
     */
    float k=200.0f;
    float x=long_spring-150.f;
    float kg=15.f;
    float g=9.8f*100.f;
    float f=0.75f;

    m.m_acc.x = -((k*x*glm::sin(angle))/kg) - m.m_vit.x*f;
    m.m_acc.y = -((k*x*glm::cos(angle))/kg) + g - m.m_vit.y*f;

    m.m_vit +=  m.m_acc * deltaTime.asSeconds() ;
    m.m_pos +=  m.m_vit * deltaTime.asSeconds() ;

    m.m_shape.setPosition(m.m_pos);
}