#include <Application/Resolver.hpp>
#include <Application/utils.hpp>
#include <chrono>
#include <thread>

void Resolver::resolve(Masse& m, const Support& s, sf::Time deltaTime){ // Suppose qu'il y a un ressort entre la masse et le support
    // Action - pesanteur
    //        - Ressort entre masse et support
    //        - C'est tout pour le moment
    sf::Vector2f m_ctr = sf::Vector2f(m.m_pos.x + m.m_shape.getSize().x/2,m.m_pos.y + m.m_shape.getSize().y/2);
    sf::Vector2f s_ctr = sf::Vector2f(s.m_pos.x + s.m_shape.getSize().x/2,s.m_pos.y + s.m_shape.getSize().y/2);

    float angle = findAngle(s_ctr,m_ctr);

    glm::vec2 m_center = glm::vec2(m.m_pos.x + m.m_shape.getSize().x/2,m.m_pos.y + m.m_shape.getSize().y/2);
    glm::vec2 s_center = glm::vec2(s.m_pos.x + s.m_shape.getSize().x/2,s.m_pos.y + s.m_shape.getSize().y/2);

    float long_spring = glm::length(glm::vec2(m_center-s_center)); // Longueur enter masse et support (en pxl, pas en m !)
    GUILogger::log("Longueur ressort" + std::to_string(long_spring));

    GUILogger::log("Angle(deg)" + std::to_string(angle) + "/ cos:: " + std::to_string(glm::cos(angle)) + "/ sin:: " + std::to_string(glm::sin(angle)));
    
    /**
     * k =2
     * lo = 150px
     * m=5kg
     */

    float k = 100.0f;
    float x = long_spring-150.f;
    float kg=15.f;
    float g =9.8f*20.f;

    m.m_acc.x = -((k*x*glm::cos(angle))/kg);
    m.m_acc.y = -((k*x*glm::sin(angle))/kg) + g;

    m.m_vit +=  m.m_acc * deltaTime.asSeconds() ;
    m.m_pos +=  m.m_vit * deltaTime.asSeconds() ;

    m.m_shape.setPosition(m.m_pos);

}