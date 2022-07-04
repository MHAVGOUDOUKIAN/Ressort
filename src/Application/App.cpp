#include <Application/App.hpp>
#include <Engine/GUILogger.hpp>
#include <glm/glm.hpp>

App::App() : m_masse(), m_support() { 
    EventHandler::getEventHandler()->addMouseObserver(this); 
    EventHandler::getEventHandler()->addKeyBoardObserver(this);
}

App::~App() {}

void App::update(sf::Time deltaTime) {
    Resolver::resolve(m_masse, m_support, deltaTime);
}

void App::notify(sf::Mouse::Button mouse, sf::Vector2i& pos, bool clicked) {
    if(mouse == sf::Mouse::Button::Left && clicked) {
        m_masse.m_pos.x = float(pos.x);
        m_masse.m_pos.y = float(pos.y);
        m_masse.m_vit.x = 0;
        m_masse.m_vit.y = 0;
    }
}


void App::notify(sf::Keyboard::Key key, bool pressed) {}

void App::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    sf::VertexArray va(sf::Lines, 2);

    va[0].position = sf::Vector2f(m_masse.m_pos.x + m_masse.m_shape.getSize().x/2,m_masse.m_pos.y + m_masse.m_shape.getSize().y/2); 
    va[1].position = sf::Vector2f(m_support.m_pos.x + m_support.m_shape.getSize().x/2,m_support.m_pos.y + m_support.m_shape.getSize().y/2); 

    va[0].color = sf::Color::Black;
    va[1].color = sf::Color::Black;

    target.draw(va);
    target.draw(m_masse);
    target.draw(m_support);
}